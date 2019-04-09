#include <stdio.h>
#include <string.h>
#include <emscripten.h>
#include <regex.h> 
 struct student
 {
 	int studentid;
 	char name[14];
 	char email[14];
 	int m1,m2,m3;
 	float avg;
 } s[50];

 int pos = 0;
 int count = 0;
 //char a[14];
char* world(char* uname, char* pwd) {
	char user[10][2];
	strcpy(user[0][0],uname);
	strcpy(user[0][1],pwd);

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(user[i][j] == user[0][0])
			{
			if(user[i][j] == user[0][1])
				return user[i][0];
			}

		}
		
	} 
} 
char* viewc(char* email){

	
	for(int i=0;i<50;i++)
	{
		 count = i;
		if (s[count].email==email)
		{
			return s[count].name;
			
		}
		else
		{
			return "we";
		}
	}

}
char* entryc(char* name, int sid, char* email, int mark1, int mark2, int mark3 ) {

	strcpy(s[pos].name,name);
	s[pos].studentid = sid;
	strcpy(s[pos].email,email);
	s[pos].m1 = mark1;
	s[pos].m2 = mark2;
	s[pos].m3 = mark3;
	s[pos].avg = (mark3+mark2+mark1)/3;
	
	return s[pos].name;
	pos++;
}
int main() {
  //world();
 

  return 0;
}

// emcc -s NO_EXIT_RUNTIME=1 -s EXPORTED_FUNCTIONS="['_world','_viewc','_entryc']" -s EXTRA_EXPORTED_RUNTIME_METHODS=["ccall"] abc.c -o abc.js