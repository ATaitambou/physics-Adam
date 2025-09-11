#include "raylib.h"
#include "raymath.h"

int main()
{

    
	InitWindow(800, 800, "Physics-Adam"); // Window size and title changes

	
	
	
	Rectangle platform;
	platform.x = 0.0f;
	platform.y = 600.0f;
	platform.width = 100.0f;
	platform.height = 20.0f;

	Rectangle ground;
	ground.x = 0.0f;
	ground.y = 780.0f;
	ground.width = 800.0f;
	ground.height = 20.0f;

	
	float radius = 10.0f;
	Vector2 launchposition;
	launchposition.x = platform.x + platform.width - radius; // Launch at right end of platform doing the math for me
	launchposition.y = platform.y - (platform.height - radius); // Launch at top of platform doing the math for me

	while (!WindowShouldClose()) // Detect window close button or ESC key
    {
		float t = GetTime();  // Get time in seconds since InitWindow()
		float dt = GetFrameTime(); // Get time in seconds for last frame drawn (delta time)
		launchposition.x += 100 * dt; // Move right at 100 pixels per second

        BeginDrawing();
            ClearBackground(WHITE); // Background changes
			DrawText("Adam Taitambou 101399640", 10, 10, 20, BLACK); // Text changes
			DrawCircleV(launchposition, 10.0f, RED);
			DrawRectangleRec(platform, BEIGE);
			DrawRectangleRec(ground, BLUE);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}



