#include "raylib.h"
#include "raymath.h"

int main()
{

    
	InitWindow(800, 800, "Physics-Adam"); // Window size and title changes

	//Vector2 circleposition_1 = { 400.0f, 400.0f }; // circle 1 position
	Vector2 launchposition = { 70.0f, 580.0f }; // circle 2 position
	//float circleradius_1 = 25.0f; // circle radius
	//Color circlecolor_1 = PURPLE;



	while (!WindowShouldClose()) // Detect window close button or ESC key
    {
		float t = GetTime();  // Get time in seconds since InitWindow()
		float dt = GetFrameTime(); // Get time in seconds for last frame drawn (delta time)

		//circleposition_1.x = 400.0f + 150.0f * sin(t); // moving left and right within 150 units forever
		//circleposition_2.y += 10.0f * dt; // moving down at 10 units per second so basically the speed


        BeginDrawing();
            ClearBackground(DARKGREEN); // Background changes
			DrawText("Adam Taitambou 101399640", 10, 10, 20, BLACK); // Text changes
			DrawCircleV(launchposition, 10.0f, RED);
			DrawRectangle(0, 600, 100, 20, BROWN);
			DrawRectangle(0, 700, 800, 20, BLUE);


			//DrawCircleV(circleposition_1, circleradius_1, circlecolor_1); // Draw circle 1 position, radius and color
			//DrawCircleV(circleposition_2, circleradius_1, RED); // Draw circle 2 position, radius and color
        EndDrawing();
    }

    CloseWindow();
    return 0;
}



