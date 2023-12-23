//Current coding standards for DogEngine 17-07-2023 


/*Commenting in general, is a little bit diffcult because what needs to be explain for someone else won't for another. 
*So to cercumnavigate this, the rule is simple and clear, short as possible. 
*/

//Comments should be like this in .h files:

//YYYY-MM-DD
//2023-07-17 

/*Comment explaining what this file does or is.*\


Comments should be like this in .cpp files in two cases: 

Case 1: 
/*
* When something is simple, but needs to be clarfied for some reason. 
*/ 
															//Example:
int simpleAddFunction(int leftHandCal_, int rightHandCal_ ) // this functions adds two numbers together. 
{														 
		int LefthandCal = leftHandCal_;					
		int RightHandCal = rightHandCal_;				
											
		int total = LefthandCal + RightHandCal;			 
									
		return total;								
														//Sometimes, its best just to clarfiy some simple functions/variables here and there 
														//so there isn't a doubt in the world exactly what it does/is.
}
/*
Case 2:
* When something is not so simple, and needs some information on how it works because , only someone who wrote it knows 
* what it does and how it works. 
*/
 Class Square 
 {
	 public:
	 Square(int x_ , int y_, int width_, int height_)
	 {
		x=x_;
		y=y_;
		width=width_;
		height= height_;
	 };
	 
	 Square operator + (Square &obj)
	 {
		 
		 
	 };
	 Square operator == (Square &obj) 
	 {
		 
		 
	 };
	 private:
	 int x,y; 
	 int width,int height;
 };
	 