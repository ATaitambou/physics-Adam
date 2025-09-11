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


	Vector2 birdvelocity = { 100.0f, 0.0f }; // Initial velocity
	Vector2 birdacceleration = { 0.0f, 9.81f }; // Gravity acceleration

	while (!WindowShouldClose()) // Detect window close button or ESC key
    {


		
		float t = GetTime();  // Get time in seconds since InitWindow()
		float dt = GetFrameTime(); // Get time in seconds for last frame drawn (delta time)
		
		//if (IsKeyPressed(KEY_SPACE))
		//{
		//	birdvelocity += birdacceleration * dt;// Change velocity when space is pressed
		//	launchposition += birdvelocity * dt; // Change position based on velocity
		//}

		birdvelocity += birdacceleration * dt;// Change velocity when space is pressed
		launchposition += birdvelocity * dt; // Change position based on velocity

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



