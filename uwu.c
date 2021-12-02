
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verbs.h"






void parse(struct Noun * nouns, struct Room * rooms,int gamerun,int time);
void removeStringTrailingNewline(char *str) ;




/////////////MAIN MAIN MAIN MAIN MAIN/////////////


void main(void){




	struct Noun nouns[MAX_NOUNS];
	struct Room rooms[MAX_ROOMS];



	/// arrays store from which room ids the room can be accessed
	///places u can reach location from, fill empty space with -2

	int basement_connections[MAX_TRAVELABLE_ROOMS] = {4,2,3,1,-2,-2,-2,-2,-2,-2};
	int living_room_connections[MAX_TRAVELABLE_ROOMS] = {0,-2,-2,-2,-2,-2,-2,-2,-2,-2};
	int cave_connections[MAX_TRAVELABLE_ROOMS] = {4,3,0,-2,-2,-2,-2,-2,-2,-2};
	int narrow_pathway_connections[MAX_TRAVELABLE_ROOMS] = {2,0,-2,-2,-2,-2,-2,-2,-2,-2};
	int wide_pathway_connections[MAX_TRAVELABLE_ROOMS] = {2,0,-2,-2,-2,-2,-2,-2,-2,-2};
	


	int filler = 0;
	for( filler = 0; (filler < MAX_NOUNS) ; filler++ ){
		create_noun(&nouns[filler], "BUFFER NAME", 90, 2, 10, 0, "BUFFER GENDER", "BUFFER S", "BUFFER S", "BUFFER S", 100,  5,  1);


	}

	for( filler = 0; (filler < MAX_ROOMS) ; filler++ ){
		create_room(&rooms[filler], "BUFFER NAME", "BUFFER DESCRIPTION", 999, basement_connections );


	}
	

///void create_noun(struct Noun *subject, char* name, int def_happy, int id, int helf, int pos, char* gender, char* subject_pronoun, char* object_pronoun,char* description,
/// int base_cost,  int damage,  int defense);
///single words only

	create_noun(&nouns[0], "anon", 100, 0, 10, 2, "m", "I", "me", "look in the mirror !" , 100,  5,  1);
	create_noun(&nouns[1], "loli", 90, 1, 10, 2, "f", "she", "her", "kawaii oneechan", 100,  5,  1);
	create_noun(&nouns[2], "shota", 90, 2, 10, 2, "m", "he", "him", "a cute boy", 100,  5,  1);
	create_noun(&nouns[3], "katana", 90, 3, 0, 2, "n", "it", "it",  "fine sword", 100,  5,  1);
	create_noun(&nouns[4], "kimono", 90, 4, 0, 2, "n", "it", "it", "traditional silk dress", 100,  5,  1);
	create_noun(&nouns[5], "terry", 90, 5, 10, 1, "m", "he", "him", "holy c", 100,  50,  1);











/// create_room(struct Room *room, char*  name,char* description, int position, int travelable_rooms[MAX_TRAVELABLE_ROOMS]);

	create_room(&rooms[0], "basement", "a nice 'basement', decorated with anime posters . there are wooden stairs to the living room. ", 0, basement_connections );
	create_room(&rooms[1], "living room", "the 'living room', there are walls of anime figurine displays . stairs lead down to the basement ", 1, living_room_connections );
	create_room(&rooms[2], "cave", "a dark wet cave with a large pool of water in it. there seem to be somewhat developed pathways leading to other parts of the cave. ", 2, cave_connections );
	create_room(&rooms[3], "narrow pathway", "tight fitting cavern corridors", 3, narrow_pathway_connections );
	create_room(&rooms[4], "wide pathway", "sprawling cavern mouths, seem well traveled", 4, wide_pathway_connections );








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









	int gamerun =1; 
	int time =0;
	





 //static const char *nouns[] = { " candy", " meowni", " shirt", " skirt", "", "", "", "", "", ""};


	////////////////// GAME INTROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO



	printf("You are in line to board a submarine. It is a refitted Ohio class SSBN that now functions primarily as a research vessel in the Arctic.\n");
	printf("The person in front of you has just finished being checked by the greeter, and you walk up to him. \n");
	printf("Following a cheery hello, the gray haired gentleman asks you for your name.\n");
	printf("Ah wonderful ! Please come inside. The man says. \n");
	printf("You board the ship and after a few ladders and stairs find yourself in the mess hall which has been converted into a fairly presentable dining room. \n");
	printf("");
	printf("");



	while (gamerun) {




		time++;

		parse(nouns, rooms, gamerun,time);




	}}


	void parse(struct Noun * nouns, struct Room * rooms,int gamerun,int time){
		






		char comm[MAX_STR_SZ];
		char string_to_parse[MAX_STR_SZ];



		
		
		
		char *room_noun_parse;
		
		
	
		char tokenized_parse[20][20];


		
		int room_object = 0;
		int statcounter = 0;
		int tokencounter =0;

		
		room_noun_parse = 0;
		

		
	

	

		static const char *verbs[] = { "pat", "tickle", "kill", "dev", "examine", "go", "take", "drop", "wield", "unwield", "attack", "give", "move", "wear", "BUFFER NAME"};
		static const char *prepositions[] = { "to", "forrr", "BUFFER NAME" };




		printf(">>> ");

		fgets(comm, MAX_STR_SZ, stdin);

 //        scanf("%s", comm);  // Note: %s is for char arrays and not %f(floats)
 //        printf("comm = %s, \n",comm);

		strcpy(string_to_parse, " ");

		strcat(string_to_parse, comm);

///TOKENIZATION
		char * token = strtok(comm, " ");
   // loop through the string to extract all other tokens
		for(tokencounter=0; token != NULL ; tokencounter++) {

			strcpy(tokenized_parse[tokencounter], token);
			removeStringTrailingNewline(tokenized_parse[tokencounter]);

		///	printf("token %d  = %s \n",tokencounter,tokenized_parse[tokencounter]);
			token = strtok(NULL, " ");
		}

   ///TOKENIZATION END

		int i = 0;
		int preposition = 0;
		int preposition_parse = 1;
		int noun1_parse = -1;
		int first_noun = -1;
		int noun2_parse = -1;
		int second_noun = -1;
		int	verb_parse = -1; /// NULL POINTER
		int verb = -1;
		


for( i = 0; ((i < tokencounter)) ; i++){
 
 	if(verb_parse){

		for( verb = 0;(strcmp(verbs[verb], "BUFFER NAME") && verb_parse); verb = verb + 1 ){
			verb_parse = strcmp(tokenized_parse[i], verbs[verb]);

		//	printf("verb parse: %d", verb_parse);



	//    printf("string_to_parse = %s, \n",string_to_parse);

		 }verb--; /// for verb

		}


				
				
				
				


			if (!noun1_parse){


				for( second_noun = 0; (strcmp(nouns[second_noun].name, "BUFFER NAME") && noun2_parse); second_noun = second_noun + 1 ){
		 	noun2_parse = strcmp(tokenized_parse[i], nouns[second_noun].name);
		 	
		 	



			}second_noun--; ///for second_noun end





			}

			if (noun1_parse){

			 for( first_noun = 0; (strcmp(nouns[first_noun].name, "BUFFER NAME") && noun1_parse); first_noun = first_noun + 1 ){
		 	noun1_parse = strcmp(tokenized_parse[i], nouns[first_noun].name);
		 	
		 	



			}first_noun--; ///for first_noun end
		}





}


///printf(" %s SET AS INDIRECT OBJECT \n %s SET AS DIRECT OBJECT \n",nouns[first_noun].name, nouns[second_noun].name);
if(noun2_parse){second_noun=first_noun;}
int noun1_parse2 = -1;






		for( i = 0; ((i < tokencounter) && preposition_parse) ; i++){
	//		printf("token2 %d  = %s \n",i,tokenized_parse[i]);
			for (preposition=0;(strcmp(prepositions[preposition], "BUFFER NAME") && preposition_parse); preposition=preposition+1){


				preposition_parse = (strcmp(prepositions[preposition], tokenized_parse[i]));
	//			printf("preposition_parse = %d \n prepositions[preposition] = %s \n tokenized_parse[i] = %s \n",preposition_parse, prepositions[preposition],tokenized_parse[i]);
				

			}
		}i--;

int x = i;
int first_noun2 = 0;
if (preposition_parse == 0){
	for( x=i ; ((x < tokencounter) && noun1_parse2) ; x++ ){

					for( first_noun2 = 0; (strcmp(nouns[first_noun2].name, "BUFFER NAME") && noun1_parse2); first_noun2 = first_noun2 + 1 ){

						


					
//							 printf("noun1_parse = %d \n nouns[first_noun].name = .%s. \n tokenized_parse[%d] = .%s. \n",noun1_parse, nouns[first_noun].name,x,tokenized_parse[x]);
		 	   noun1_parse2 = strcmp(nouns[first_noun2].name, tokenized_parse[x]);
		 	   if(!noun1_parse2 && (first_noun !=first_noun2 )){

		 	   		second_noun = first_noun;
		 	   		first_noun = first_noun2;






		 	   }
		 

		 }
		 	
		 	



			}




				}


		 


////printf(" %s SET AS INDIRECT OBJECT \n %s SET AS DIRECT OBJECT \n",nouns[first_noun].name, nouns[second_noun].name);




	



			for( room_object = 0; (strcmp(rooms[room_object].name, "BUFFER NAME") && !room_noun_parse); room_object = room_object + 1 ){
				
				room_noun_parse = strstr(string_to_parse, rooms[room_object].name);
	//			printf("room_object = %d",room_object);
				



			}room_object--; ///for second_noun end


//		printf("verb = %d indirect object = %d direct object = %d",verb,first_noun,second_noun);

 ///parse match events

			if (!verb_parse ){
  ///           printf("MEOW\n");
				

	if ( room_noun_parse){//printf("WAHTTHEHECK %d %d %s",room_object, verb, verbs[verb] );

				if (((strcmp(verbs[verb], "examine"))==0) && room_noun_parse){
					examine_room(&nouns[0], &rooms[room_object], nouns,rooms);
		 //           printf("Tss ~\n");

				}

				if (!(strcmp(verbs[verb], "go")) || !(strcmp(verbs[verb], "move"))){
					
					

					move(&nouns[0], &rooms[room_object]);
					examine_room(&nouns[0], &rooms[room_object],nouns,rooms);
					
		// BUFFER NAME			
	 //               printf("Tss ~\n");

				}




			}
				


////	static const char *verbs[] = { " pat", " tickle", " kill", " dev", " examine", " go", " take", " drop", " wield", " unwield", " attack", "BUFFER NAME", ""};
				if (!noun1_parse){

					if ((strcmp(verbs[verb], "pat"))==0){
						headpat(&nouns[0], &nouns[first_noun]);


					}

					if ((strcmp(verbs[verb], "kill"))==0){
						printf("You kill the loli . Fun .\n");
						gamerun = 0;
					}

					if ((strcmp(verbs[verb], "dev"))==0){
						printf("happy = %i, verbs[1] = %s, \n",nouns[1].happy, verbs[1]);
						printf("nouns[second_noun].name = %s, \n",nouns[second_noun].name);
						printf(" rooms[0].name %s rooms[0].description %s ! rooms[0].travelable_rooms[1] %d  .\n", rooms[0].name, rooms[0].description, rooms[0].travelable_rooms[1] );
						nouns[1].happy = nouns[1].happy + 10;

					}

					if ((strcmp(verbs[verb], "examine")==0)&& noun2_parse){
						examine_noun(&nouns[0], &nouns[first_noun]);

					}

					

					

					if ((strcmp(verbs[verb], "take"))==0){
						
						take_noun( &nouns[0], &rooms[nouns[0].position], &nouns[first_noun]);

					}

					if ((strcmp(verbs[verb], "drop"))==0){

						drop_noun( &nouns[0], &rooms[nouns[0].position], &nouns[first_noun]);

					}
					if (!(strcmp(verbs[verb], "wield")) || !(strcmp(verbs[verb], "wear"))){

						wield_noun( &nouns[0],  &nouns[first_noun]);

					}
					if ((strcmp(verbs[verb], "unwield"))==0){

						unwield_noun( &nouns[0],  &nouns[first_noun]);

					}

					if ((strcmp(verbs[verb], "attack"))==0){

						attack(&nouns[0], &nouns[first_noun], nouns);

					}

					if ((strcmp(verbs[verb], "give"))==0){

						give_noun(&nouns[0], &nouns[second_noun], &nouns[first_noun]);

					}



			}  /// if  noun parse end

		



	} ///if verb parse end



	for( statcounter = 0;(strcmp(nouns[statcounter].name,"BUFFER NAME")); statcounter = statcounter + 1 ){

			///stat events

		if ( (nouns[statcounter].health < 0 ) && (nouns[statcounter].alive == 1)){

			printf("%s has died !\n",nouns[statcounter].name);
			nouns[statcounter].alive = 0;

		}

	   }  ///for stat events


	if (nouns[0].main_quest == 0){
		
		
	///	printf("nyaa");
		
		
		
	}





	}//// parse function declaration end








	void removeStringTrailingNewline(char *str) {
  if (str == NULL)
    return;
  int length = strlen(str);
  if ((str[length-1] == '\n') || (str[length-1] == '\n'))
    str[length-1]  = '\0';
}

