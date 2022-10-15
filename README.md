# SFML GameEngine Prototype developed by Ilmārs Kuhtarskis (in progress)


**The Main menu involves:**
  - Seamless switches between states of game e.g. (Main menu and Game state)
  - Only the current state is being processed at a time
  - Highly customizable buttons
  - Custom Scatter plot and Line charts
  
![Screenshot (92)](https://user-images.githubusercontent.com/115834230/195986003-481a3d7d-0b9d-49c2-a31c-defa39ea7b14.png)

**Game state involves:**
  - Collision with border of window
  - Customizable gravity
  - Custom hitbox for collision component
  - Movement component (Moving left, right, up , down, jump)
  - Shooting component for projectiles and automatic projectile cleanup
 
![Screenshot (114)](https://user-images.githubusercontent.com/115834230/195986297-c46abd98-930b-4729-8358-1ec84fd479d7.png)

**Deep learning Project:**
 
Computer was trained to recognize blue flowers from red flowers using labeled data.

Input given to the comptuter was the length and width of the flower and the type of flower.

Training Data set (Length, Width, Color(1 - red, 0 - blue)) 
### TRAINING DATASET REPRESENTED WITH SOLID RED AND BLUE COLORS

  {3,   1.5, 1}
  {2,   1,   0}
  {4,   1.5, 1}
  {3.5, .5,  1}
  {2,   .5,  0}
  {5.5,  1,  1}
  {1,    1,  0}

Using Gradient Descent and Backpropagation weights and bias was adjusted depending on how correct the computer answer was.

The first graph shows Training Set and transparent circles represent computer predictions (the line of best fit can be seen in border between red and blue)

The second graph displays the cost over the whole dataset (Higher cost = more wrong predictions)
  
![Screenshot (118)](https://user-images.githubusercontent.com/115834230/195986554-9deb18e9-112f-404a-8916-306b77a91e4a.png)

