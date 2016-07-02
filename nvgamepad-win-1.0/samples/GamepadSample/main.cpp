//----------------------------------------------------------------------------------
// File:        GamepadSample/main.cpp
// SDK Version: v1.0 
// Email:       gameworks@nvidia.com
// Site:        http://developer.nvidia.com/
//
// Copyright (c) 2014, NVIDIA CORPORATION. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------------

#include <NvGamepad/NvGamepad.h>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

static NvGamepad* sGamepad = NULL;
static uint32_t sChangedMask = 0;
static std::string sStatusString = "No events yet";
static std::string sPlayerStatusString = "No movement yet";
// initial player state
static int sPlayerXCoordinate = 0;
static int sPlayerHorizontalSpeed = 1;
static int sPlayerVerticalSpeed = 40;
static int sPlayerYCoordinate = 0;
// initial Jump statut
static bool sPlayerJumpFlag = false;
static int sJumpIteration = 1;
// physics constants
static double sTimeConstant = 0.016;
static float sAirFriction = 1;
static float sGravity = 10;


extern std::string ProcessGamepad(NvGamepad* pad) {
    std::stringstream str;

    NvGamepad::State state;

    if (pad->getState(0, state)) {
        str << "Buttons: 0x" << std::hex << std::setfill('0') << std::setw(8) << state.mButtons << std::endl;;
        str << "Left Stick: (" << state.mThumbLX << ", " << state.mThumbLY << ")" << std::endl;
        str << "Right Stick: (" << state.mThumbRX << ", " << state.mThumbRY << ")" << std::endl;
        str << "Triggers: (" << state.mLeftTrigger << ", " << state.mRightTrigger << ")" << std::endl;
    }

    return str.str();
}


extern std::string ProcessPlayerMove(NvGamepad* pad) { 
    std::stringstream str;
	float JumpTime = 0;
	float DeltaYCoordinate = 0;
    NvGamepad::State state;

    if (pad->getState(0, state)) {//Controller change state detection
		if ((state.mButtons == 4096)&&(sPlayerJumpFlag == false)) { // on A pressed 
			sPlayerJumpFlag = true; // activate jump
		}
		sPlayerXCoordinate = sPlayerXCoordinate + int(sPlayerHorizontalSpeed*state.mThumbLX); // on horizontal move of Left Thumb move player
    }
	if (sPlayerJumpFlag == true) { // Jump routine
		JumpTime = float(sJumpIteration)*float(sTimeConstant);// Calculate jump statut in time scale
		DeltaYCoordinate = float(sTimeConstant*((sPlayerVerticalSpeed*sAirFriction*sGravity*exp((-1 * JumpTime) / sAirFriction)) - (sGravity*sAirFriction))); // Calculating Player deltaY coordinate 
		sPlayerYCoordinate = int(float(sPlayerYCoordinate) + DeltaYCoordinate); // Adding deltaY coordinate to current Y coordinate
		sJumpIteration++; // Incrementing jump statut
	}
	if ((sPlayerYCoordinate <= 0) && (sPlayerJumpFlag == true)) { //detecting collision with ground
		sPlayerYCoordinate = 0; // Setting Player Y position to Ground level
		sJumpIteration = 1; // Reseting Jump statut
		sPlayerJumpFlag = false; // Turning of jump routine
	}
	// Return player info
	str << "Player X Coordinate : " << sPlayerXCoordinate << std::endl;
    str << "Player Y Coordinate : " << sPlayerYCoordinate << std::endl;
	str << "Delta Y Coordinate : " << DeltaYCoordinate << std::endl;
	str << "Jump Time :" << JumpTime << std::endl;
    str << "Jump :" << sPlayerJumpFlag << std::endl;

	
    return str.str();
}

#ifdef ANDROID
#include <android/log.h>
#include "nv_native_app_glue.h"
#include <NvGamepad/NvGamepadAndroid.h>

static NvGamepadAndroid* sGamepadAndroid = NULL;

static int32_t HandleEvents(struct android_app* app, AInputEvent* event) {
    return sGamepadAndroid->pollGamepads(event, sChangedMask) ? 1 : 0;
}

/**
 * This is the main entry point of a native application that is using
 * android_native_app_glue.  It runs in its own thread, with its own
 * event loop for receiving input events and doing other things.
 */
void android_main(struct android_app* app) {
    // Make sure glue isn't stripped.
    app_dummy();

    sGamepadAndroid = new NvGamepadAndroid;
    sGamepad = sGamepadAndroid;

    app->onInputEvent = &HandleEvents;
    app->onAppCmd = NULL;

    while (nv_app_status_running(app)) {
        // Read all pending events.
        int ident;
        int events;
        struct android_poll_source* source;

        // If not rendering, we will block 250ms waiting for events.
        // If animating, we loop until all events are read, then continue
        // to draw the next frame of animation.
        while ((ident = ALooper_pollAll(nv_app_status_focused(app) ? 1 : 250,
            NULL, &events, (void**)&source)) >= 0) {
            // Process this event. 
            if (source != NULL)
                source->process(app, source);

            // Check if we are exiting.  If so, dump out
            if (!nv_app_status_running(app))
                break;
        }

        if (sChangedMask) {
            std::string str = ProcessGamepad(sGamepad);
            __android_log_print(ANDROID_LOG_INFO, "NvGamepad",  "%s", str.c_str());
            sChangedMask = 0;
        }
    }

    exit(0);
}

#endif

#ifdef _WIN32
#include <Windows.h>
#include <NvGamepad/NvGamepadXInput.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    switch( message ) {
        case WM_PAINT: {
            HDC hdc;
            PAINTSTRUCT ps;
            RECT rect;
            InvalidateRect(hwnd,NULL,FALSE);
            hdc = BeginPaint( hwnd, &ps );

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            // Draw the last gamepad status to the window
            GetClientRect(hwnd, &rect);
            DrawText(hdc, sStatusString.c_str(), -1, &rect, 0);

            EndPaint( hwnd, &ps );
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc( hwnd, message, wparam, lparam );
}

// program entry
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    bool running = true;

    NvGamepadXInput* gamepadXInput = new NvGamepadXInput;
    sGamepad = gamepadXInput;

    WNDCLASS wc;
    wc.cbClsExtra = 0; 
    wc.cbWndExtra = 0; 
    wc.hbrBackground = (HBRUSH)0;
    wc.hCursor = 0;
    wc.hIcon = 0;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = TEXT("Gamepad");
    wc.lpszMenuName = 0; 
    wc.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wc);
    HWND hwnd = CreateWindow(TEXT("Gamepad"), TEXT("Nv Gamepad Sample"),
        WS_OVERLAPPEDWINDOW, 0, 0, 640, 480,
        NULL, NULL, hInstance, NULL );
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(running) {
        MSG msg;

        if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) ) {
            if( msg.message == WM_QUIT ) {
                running = false;
                break;
            }

            TranslateMessage( &msg );
            DispatchMessage( &msg );
        } else {
            sChangedMask |= gamepadXInput->pollGamepads();
			//sChangedMask//
            if (1) {
				Sleep(DWORD(sTimeConstant*1000));
                sStatusString = ProcessGamepad(sGamepad);
				sStatusString = sStatusString + ProcessPlayerMove(sGamepad);
                // Log the latest values
                OutputDebugString(sStatusString.c_str());

                // Force a paint to the window, so we print the latest values
                RedrawWindow(hwnd, NULL, 0, RDW_INVALIDATE);

                sChangedMask = 0;
            }
        }
    }

    // Exit program
    exit( EXIT_SUCCESS );
}



#endif
