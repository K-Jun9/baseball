#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

enum{Out, Hit, Double, Triple, HR, BB};

int SK08() {

	int bat;
	int batSK;

	bat = rand() % 5003;
	if (bat >= 0 && bat < 2886) {
		batSK = 0;
	}
	else if (bat >= 2886 && bat < 4108) {
		batSK = 1;
	}
	else if (bat >= 4108 && bat < 4323) {
		batSK = 2;
	}
	else if (bat >= 4323 && bat < 4346) {
		batSK = 3;
	}
	else if (bat >= 4346 && bat < 4435) {
		batSK = 4;
	}
	else if (bat >= 4435 && bat < 5003) {
		batSK = 5;
	}
	return batSK;
}

int 吩单08() {

	int bat;
	int bat吩单;

	bat = rand() % 4890;
	if (bat >= 0 && bat < 2842) {
		bat吩单 = 0;
	}
	else if (bat >= 2842 && bat < 4042) {
		bat吩单 = 1;
	}
	else if (bat >= 4042 && bat < 4241) {
		bat吩单 = 2;
	}
	else if (bat >= 4241 && bat < 4263) {
		bat吩单 = 3;
	}
	else if (bat >= 4263 && bat < 4356) {
		bat吩单 = 4;
	}
	else if (bat >= 4356 && bat < 4890) {
		bat吩单 = 5;
	}
	return bat吩单;
}

main() 
{
	int outcount;
	int batter;
	int bat;
	int scoreboard[2][10];
	int score = 0;
	int total1 = 0;
	int total2 = 0;
	int win1 = 0;
	int win2 = 0;
	int lose1 = 0;
	int lose2 = 0;
	int draw = 0;
	int gc = 0;
	bool base[4];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			scoreboard[i][j] = 0;
		}
	}
	
	srand(time(NULL));
	outcount = 0;
	for (int g = 1; g < 18; g++) {
		score = 0;
		total1 = 0;
		total2 = 0;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 10; j++) {
				scoreboard[i][j] = 0;
			}
		}
		printf("Game %d : SCORE BOARD\n\n", g);

		for (int i = 0; i < 9; i++) {
			outcount = 0;
			base[0] = 0;
			base[1] = 0;
			base[2] = 0;
			base[3] = 0;
			batter = 0;

			while (outcount < 3) {

				batter = SK08();

				switch (batter) {

				case Out:
					outcount = outcount++;

					break;

				case Hit:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						base[1] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						base[1] = 1;
						base[2] = 0;
						base[3] = 1;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						base[1] = 1;
						base[3] = 0;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 0;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						base[1] = 1;
						base[2] = 0;
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
						score = score++;
					}

					break;

				case Double:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						base[2] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						base[1] = 0;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						base[2] = 1;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						base[2] = 1;
						base[3] = 0;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						base[1] = 0;
						base[2] = 1;
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						base[1] = 0;
						base[2] = 1;
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						base[2] = 1;
						base[3] = 0;
						score = score + 2;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						base[1] = 0;
						base[2] = 1;
						base[3] = 0;
						score = score + 3;
					}
					break;

				case Triple:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						base[3] = 1;
						score = score + 2;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						base[3] = 1;
						score = score + 2;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						base[3] = 1;
						score = score + 2;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						base[3] = 1;
						score = score + 3;
					}

					break;

				case HR:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						score = score++;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						score = score + 2;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						score = score + 2;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						score = score + 2;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						score = score + 3;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						score = score + 3;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						score = score + 3;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						score = score + 4;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					break;

				case BB:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						base[1] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						base[1] = 1;
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
						score = score++;
					}

					break;
				}

			}
			scoreboard[0][i] = score;

			outcount = 0;
			base[0] = 0;
			base[1] = 0;
			base[2] = 0;
			base[3] = 0;
			batter = 0;
			score = 0;

			while (outcount < 3) {
				
				batter = 吩单08();

				switch (batter) {

				case Out:
					outcount = outcount++;

					break;

				case Hit:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						base[1] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						base[1] = 1;
						base[2] = 0;
						base[3] = 1;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						base[1] = 1;
						base[3] = 0;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 0;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						base[1] = 1;
						base[2] = 0;
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
						score = score++;
					}

					break;

				case Double:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						base[2] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						base[1] = 0;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						base[2] = 1;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						base[2] = 1;
						base[3] = 0;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						base[1] = 0;
						base[2] = 1;
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						base[1] = 0;
						base[2] = 1;
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						base[2] = 1;
						base[3] = 0;
						score = score + 2;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						base[1] = 0;
						base[2] = 1;
						base[3] = 0;
						score = score + 3;
					}
					break;

				case Triple:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						base[3] = 1;
						score = score++;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						base[3] = 1;
						score = score + 2;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						base[3] = 1;
						score = score + 2;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						base[3] = 1;
						score = score + 2;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						base[3] = 1;
						score = score + 3;
					}

					break;

				case HR:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						score = score++;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						score = score + 2;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						score = score + 2;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						score = score + 2;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						score = score + 3;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						score = score + 3;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						score = score + 3;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						score = score + 4;
						base[0] = 0;
						base[1] = 0;
						base[2] = 0;
						base[3] = 0;
					}
					break;

				case BB:
					if (base[1] == 0 && base[2] == 0 && base[3] == 0) {
						base[1] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
					}
					else if (base[1] == 0 && base[2] == 0 && base[3] == 1) {
						base[1] = 1;
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 0) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 0 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 0 && base[2] == 1 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
					}
					else if (base[1] == 1 && base[2] == 1 && base[3] == 1) {
						base[1] = 1;
						base[2] = 1;
						base[3] = 1;
						score = score++;
					}

					break;
				}
			}
			scoreboard[1][i] = score;

		}

		for (int i = 0; i < 9; i++) {
			total1 = total1 + scoreboard[0][i];
		}
		scoreboard[0][9] = total1;

		for (int i = 0; i < 9; i++) {
			total2 = total2 + scoreboard[1][i];
		}
		scoreboard[1][9] = total2;

		printf("08SK  ");
		for (int i = 0; i < 10; i++) {
			printf("%4d ", scoreboard[0][i]);
		}
		printf("\n");
		printf("08吩单");
		for (int i = 0; i < 10; i++) {
			printf("%4d ", scoreboard[1][i]);
		}
		printf("\n\n");
		
		if (total1 > total2) {
			win1++;
			lose2++;
		}
		else if (total1 < total2) {
			win2++;
			lose1++;
		}
		else if (total1 = total2) {
			draw++;
		}
	}
	printf("08SK : %d铰 %d公 %d 菩\n", win1, draw, lose1);
	printf("08吩单 : %d铰 %d公 %d 菩\n", win2, draw, lose2);

}