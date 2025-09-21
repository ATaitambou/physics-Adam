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
	Vector2 birdposition;
	birdposition.x = platform.x + platform.width - radius; // Launch at right end of platform doing the math for me
	birdposition.y = platform.y - (platform.height - radius); // Launch at top of platform doing the math for me

	float launchSpeed = 150.0f;
	float launchAngle = 45.0f;

	// Reassign launchvelocity like when space is pressed part 1
	Vector2 launchposition = birdposition; // Store start position for reset
	Vector2 launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed; // Calculate launch velocity from angle and speed
	Vector2 futureLaunchVelocity = launchVelocity; // For drawing the launch angle line


	Vector2 birdvelocity = launchVelocity; // Initial velocity
	Vector2 birdacceleration = { 0.0f, 9.81f }; // Gravity acceleration


	while (!WindowShouldClose()) // Detect window close button or ESC key
    {


		
		float t = GetTime();  // Get time in seconds since InitWindow()
		float dt = GetFrameTime(); // Get time in seconds for last frame drawn (delta time)


		launchVelocity = launchVelocity + birdacceleration * dt;

		//When key is pressed lab 2
		if(IsKeyPressed(KEY_SPACE)) // Reset position and velocity when space is pressed
		{

			birdposition = launchposition;// 1. Set bird position to launch position 
			birdvelocity = launchVelocity;// 2. Set bird velocity based on the launch angle and launchspeed see intial launchvelocity asssignemnt 
			
			
			
		}
		if (IsKeyDown(KEY_DOWN)) // Increasing launch angle
		{
			launchAngle += 1.5f * dt;
			launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed;// Tried leaving as is but it woildnt be illistrated so leave it in 
			birdvelocity = launchVelocity;
			
		}
		if (IsKeyDown(KEY_UP)) // Decreasing launch angle
		{
			launchAngle -= 1.5f * dt;
			launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed;
			birdvelocity = launchVelocity;
		}
		if (IsKeyDown(KEY_RIGHT)) // Increasing launch speed
		{
			launchSpeed += 200.0f * dt;
			launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed;
			birdvelocity = launchVelocity;
			
		}
		if(IsKeyDown(KEY_LEFT)){  // Decreasing launch speed
			launchSpeed -= 200.0f * dt ;
			launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed;
			birdvelocity = launchVelocity;
		}
		if (IsKeyDown(KEY_FIVE)) {

			

		}
		
		if(IsKeyDown(KEY_ESCAPE))
		{
			CloseWindow();
		}
		
		futureLaunchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed; // For drawing the launch angle line
		
		birdvelocity += birdacceleration * dt;// Change velocity when space is pressed
		birdposition += birdvelocity * dt; // Change position based on velocity

        BeginDrawing();
            ClearBackground(WHITE); // Background changes

			//Where our bird is drawn and the platform and ground
			//DrawCircleV(birdposition, radius, RED);
			DrawCircleV(launchposition, radius,DARKBLUE);
			DrawRectangleRec(platform, BEIGE);
			DrawRectangleRec(ground, BLUE);

			//Displaying the launch angle line
			DrawLineV(launchposition, launchposition + futureLaunchVelocity,GOLD);

			// Texts That are added to the screen
			DrawText("Adam Taitambou 101399640", 10, 10, 20, BLACK);
			DrawText(TextFormat("Launch Position: %f %f ",launchposition.x, launchposition.y),10,30,20, BLACK);
			DrawText(TextFormat("Launch Angle: %f ", launchAngle), 10, 50, 20, BLACK);
			DrawText(TextFormat("Launch Speed: %f ", launchSpeed), 10, 70, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}



