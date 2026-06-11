#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void limpar()
{
    printf("\033[H\033[?25l");
}

int main()
{
	srand(time(NULL));
	
	char selecao;
	char continuar;
	menu:
	morte:
	printf("*-------------------------------------*\n"); 
	printf("|                                     |\n"); 
	printf("|          Dungeon Crawler            |\n");
	printf("|                                     |\n"); 
	printf("|             a: Tutorial             |\n");
	printf("|             b: Sair                 |\n");
	printf("|                                     |\n");
	printf("| Pressione qualquer tecla para jogar |\n");
	printf("|                                     |\n"); 
	printf("*-------------------------------------*\n\n"); 
	
	printf("Escolha: ");
	selecao = getch();
	
	if(selecao == 'a'){
		printf("*---------------------------------------*\n"); 
		printf("| <>v^ --- Seu personagem               |\n"); 
		printf("| * --- Paredes                         |\n");
		printf("| # --- Espinhos                        |\n"); 
		printf("| k --- Caixas (Possivel destruir)      |\n");
		printf("| o --- Botao                           |\n");
		printf("| D --- Porta fechada                   |\n");
		printf("| = --- Pora aberta                     |\n"); 
		printf("| @ --- Chave                           |\n");
		printf("| L --- Escada (passa pra proxima fase) |\n"); 
		printf("| X --- Monstro 1 (movimento aleatorio) |\n"); 
		printf("| Y --- Monstro 2 (persegue jogador)    |\n"); 
		printf("| Z --- Monstro 3                       |\n");
		printf("| W --- Cima                            |\n");
		printf("| S --- Baixo                           |\n");
		printf("| A --- Esquerda                        |\n");
		printf("| D --- Direita                         |\n");
		printf("| I --- Interagir                       |\n");
		printf("| O --- Ataque                          |\n");
		printf("| H --- NPC                             |\n");
		printf("*---------------------------------------*\n\n");
		
		printf("Voce tem 3 vidas, se perder as 3 o jogo reinicia.\n");
		
		printf("\nPressione qualquer tecla pra prosseguir: ");
		continuar = getch();
		system("cls");
		goto menu;
	}else if(selecao == 'b'){
		return 0;
	}
	
    int x = 7, y = 6;
    int i, j;
    int vida_bot = 1;
    int vida_botP = 1;
    int PIx = 1, PIy = 5;
    
    char vila[10][10] = {
        {'*', '*', '*', '*', '*', ' ', '*', '*', '*', '*'},
        {'*', ' ', ' ', ' ', '*', 'L', '*', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', 'H', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}  
    };
    
    char vila1[10][10] = {
        {'*', '*', '*', '*', '*', 'L', '*', '*', '*', '*'},
        {'*', ' ', ' ', ' ', '*', 'D', '*', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', 'k', 'k', 'k', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', 'H', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', 'k', 'k', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', 'k', '@', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}  
    };

    
    char input;
    char arma_atual = ' ';
    int vida = 3;
    vila[x][y] = '>';
    
    #ifdef _WIN32
       system("cls");
    #else
        system("clear");
    #endif  
    
    int botX = 8, botY = 8, direcao;
    int botXP = 1, botYP = 1;
	vila:
	if(vida_bot < 1){ vida_bot = 1; }
	if(vida_botP < 1){ vida_botP = 1; }
	x = 7; 
	y = 6; 
	
	botX = 8; 
	botY = 8;
	
 	vila[x][y] = '>';
 	//vila[botX][botY] = 'X';
 	// vila[botXP][botYP] = 'Y';
     
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("%c ", vila[i][j]);
        }
        printf("\n");
    }
    
    while(1)
    {
        input = getch();
        limpar();
        
        
        if(input == 's' || input == 'S'){ // Pra baixo
            if(x < 9){
                if(vila[x+1][y] != '*' && vila[x+1][y] != 'D' && vila[x+1][y] != 'H'){ 
                    vila[x][y] = ' ';
                    x = x + 1;
                    vila[x][y] = 'v';
                }
            }
        }else if(input == 'w' || input == 'W'){ // Pra Cima
            if(x > 0){
                if(vila[x-1][y] != '*' && vila[x-1][y] != 'D' && vila[x-1][y] != 'H'){ 
                    vila[x][y] = ' ';
                    x = x - 1;
                    vila[x][y] = '^';
                }
            }
        }else if(input == 'd' || input == 'D'){ // Pra direita
            if(y < 9){
                if(vila[x][y+1] != '*' && vila[x][y+1] != 'D' && vila[x][y+1] != 'H'){ 
                    vila[x][y] = ' ';
                    y = y + 1;
                    vila[x][y] = '>';
                }
            }
        }else if(input == 'a' || input == 'A'){ // Pra esquerda
            if(y > 0){
                if(vila[x][y-1] != '*' && vila[x][y-1] != 'D' && vila[x][y-1] != 'H'){ 
                    vila[x][y] = ' ';
                    y = y - 1;       
                    vila[x][y] = '<';
                }
            }
        }
        
        if(vila[x][y] == vila[1][5]){ 
			system("cls");
			break; 
		}
        
        
		
        vila[5][2] = '#';
        if(x == 5 && y == 2){
			vida--;
			if(vida == 0){
    			system("cls");
				printf("voce perdeu...\n");
				goto morte;
			}
			
        	system("cls"); 
			printf("Voce morreu, pressione qualquer tecla para tentar novamente");			
			
			getch();
			system("cls");
			
			goto vila;
		}
        
        
		// Interação com o npc  
        if (input == 'i' || input == 'I') {
            
            if (vila[x+1][y] == 'H' || vila[x-1][y] == 'H' || vila[x][y+1] == 'H' || vila[x][y-1] == 'H') {
                
                system("cls");
                
                printf("--- npc buxa ---\n");
                printf("escolhe ae mano\n");
                printf("1: Espada\n");
                printf("2: Arco\n");
                printf("3: Cajado\n");
                printf("-----------------\n");
                printf("Escolha o numero da arma para selecionar.\nCaso nao queira digite qualquer tecla.");
                char escolha = getch(); 

                if (escolha == '1') {
                    arma_atual = 'E';
                    printf("\n\nVoce equipou a ESPADA!");
                } 
                else if (escolha == '2') {
                    arma_atual = 'A';
                    printf("\n\nVoce equipou o ARCO!");
                } 
                else if (escolha == '3') {
                    arma_atual = 'C';
                    printf("\n\nVoce equipou o CAJADO!");
                }

                printf("\nPressione qualquer tecla para fechar o menu");
                getch(); 
                system("cls");
            } 
        } 
        
        if(input == 'o' || input == 'O') {
            

            if (arma_atual == 'E') {
                if(vila[x][y]=='v'){
                    if(x+1 < 10 && vila[x+1][y]=='*'){
                        vila[x+1][y]='*';
                    }else if(x+1 < 10){
                        vila[x+1][y]=' ';
                    } 
                    if(x+2 < 10 && vila[x+2][y]=='*'){
                        vila[x+2][y]='*';
                    }else if (x+2 < 10 && vila[x+1][y]!='*'){
                        vila[x+2][y]=' ';
                    }
                    
                    if(x+1 < 10 && y+1 < 10 && vila[x+1][y+1]=='*'){
                        vila[x+1][y+1]='*';
                    }else if(x+1 < 10 && y+1 < 10){
                        vila[x+1][y+1]=' ';
                    } 
                    if(x+2 < 10 && y+1 < 10 && vila[x+2][y+1]=='*'){
                        vila[x+2][y+1]='*';
                    }else if(x+2 < 10 && y+1 < 10){
                        vila[x+2][y+1]=' ';
                    }
                    
                    if(x+1 < 10 && y-1 >= 0 && vila[x+1][y-1]=='*'){
                        vila[x+1][y-1]='*';
                    }else if(x+1 < 10 && y-1 >= 0){
                        vila[x+1][y-1]=' ';
                    } 
                    if(x+2 < 10 && y-1 >= 0 && vila[x+2][y-1]=='*'){
                        vila[x+2][y-1]='*';
                    }else if(x+2 < 10 && y-1 >= 0){
                        vila[x+2][y-1]=' ';
                    }
                }
                
                if(vila[x][y]=='>'){
                    if(y+1 < 10 && vila[x][y+1]=='*'){
                        vila[x][y+1]='*';
                    }else if(y+1 < 10){
                        vila[x][y+1]=' ';
                    } 
                    if(y+2 < 10 && vila[x][y+2]=='*'){
                        vila[x][y+2]='*';
                    }else if (y+2 < 10 && vila[x][y+1]!='*'){
                        vila[x][y+2]=' ';
                    }
                    
                    if(x+1 < 10 && y+1 < 10 && vila[x+1][y+1]=='*'){
                        vila[x+1][y+1]='*';
                    }else if(x+1 < 10 && y+1 < 10){
                        vila[x+1][y+1]=' ';
                    } 
                    if(x+1 < 10 && y+2 < 10 && vila[x+1][y+2]=='*'){
                        vila[x+1][y+2]='*';
                    }else if(x+1 < 10 && y+2 < 10){
                        vila[x+1][y+2]=' ';
                    }
                    
                    if(x-1 >= 0 && y+1 < 10 && vila[x-1][y+1]=='*'){
                        vila[x-1][y+1]='*';
                    }else if(x-1 >= 0 && y+1 < 10){
                        vila[x-1][y+1]=' ';
                    } 
                    if(x-1 >= 0 && y+2 < 10 && vila[x-1][y+2]=='*'){
                        vila[x-1][y+2]='*';
                    }else if(x-1 >= 0 && y+2 < 10){
                        vila[x-1][y+2]=' ';
                    }
                }
                
                if(vila[x][y]=='<'){
                    if(y-1 >= 0 && vila[x][y-1]=='*'){
                        vila[x][y-1]='*';
                    }else if(y-1 >= 0){
                        vila[x][y-1]=' ';
                    } 
                    if(y-2 >= 0 && vila[x][y-2]=='*'){
                        vila[x][y-2]='*';
                    }else if (y-2 >= 0 && vila[x][y-1]!='*'){
                        vila[x][y-2]=' ';
                    }
                    
                    if(x+1 < 10 && y-1 >= 0 && vila[x+1][y-1]=='*'){
                        vila[x+1][y-1]='*';
                    }else if(x+1 < 10 && y-1 >= 0){
                        vila[x+1][y-1]=' ';
                    }
                    if(x+1 < 10 && y-2 >= 0 && vila[x+1][y-2]=='*'){
                        vila[x+1][y-2]='*';
                    }else if(x+1 < 10 && y-2 >= 0){
                        vila[x+1][y-2]=' ';
                    }
                    
                    if(x-1 >= 0 && y-1 >= 0 && vila[x-1][y-1]=='*'){
                        vila[x-1][y-1]='*';
                    }else if(x-1 >= 0 && y-1 >= 0){
                        vila[x-1][y-1]=' ';
                    } 
                    if(x-1 >= 0 && y-2 >= 0 && vila[x-1][y-2]=='*'){
                        vila[x-1][y-2]='*';
                    }else if(x-1 >= 0 && y-2 >= 0){
                        vila[x-1][y-2]=' ';
                    }
                }
                
                if(vila[x][y]=='^'){
                    if(x-1 >= 0 && vila[x-1][y]=='*'){
                        vila[x-1][y]='*';
                    }else if(x-1 >= 0){
                        vila[x-1][y]=' ';
                    } 
                    if(x-2 >= 0 && vila[x-2][y]=='*'){
                        vila[x-2][y]='*';
                    }else if (x-2 >= 0 && vila[x-1][y]!='*'){
                        vila[x-2][y]=' ';
                    }
                    
                    if(x-1 >= 0 && y+1 < 10 && vila[x-1][y+1]=='*'){
                        vila[x-1][y+1]='*';
                    }else if(x-1 >= 0 && y+1 < 10){
                        vila[x-1][y+1]=' ';
                    } 
                    if(x-2 >= 0 && y+1 < 10 && vila[x-2][y+1]=='*'){
                        vila[x-2][y+1]='*';
                    }else if(x-2 >= 0 && y+1 < 10){
                        vila[x-2][y+1]=' ';
                    }
                    
                    if(x-1 >= 0 && y-1 >= 0 && vila[x-1][y-1]=='*'){
                        vila[x-1][y-1]='*';
                    }else if(x-1 >= 0 && y-1 >= 0){
                        vila[x-1][y-1]=' ';
                    } 
                    if(x-2 >= 0 && y-1 >= 0 && vila[x-2][y-1]=='*'){
                        vila[x-2][y-1]='*';
                    }else if(x-2 >= 0 && y-1 >= 0){
                        vila[x-2][y-1]=' ';
                    }
                }
            }

            else if (arma_atual == 'A') {
                if(vila[x][y]=='^'){
                    if(x-1 >= 0 && vila[x-1][y]=='*'){
                        vila[x-1][y]='*';
                    }else if(x-1 >= 0){    
                        vila[x-1][y]=' ';
                    } 
                    if(x-2 >= 0 && vila[x-2][y]=='*'){
                        vila[x-2][y]='*';
                    }else if(x-2 >= 0){
                        vila[x-2][y]=' ';
                    }
                    if(x-3 >= 0 && vila[x-3][y]=='*'){
                        vila[x-3][y]='*'; 
                    }else if(x-3 >= 0){
                        vila[x-3][y]=' ';
                    }
                    if(x-4 >= 0 && vila[x-4][y]=='*'){
                        vila[x-4][y]='*'; 
                    }else if(x-4 >= 0){
                        vila[x-4][y]=' ';
                    }
                }
                if(vila[x][y]=='v'){
                    if(x+1 < 10 && vila[x+1][y]=='*'){
                        vila[x+1][y]='*';
                    }else if(x+1 < 10){    
                        vila[x+1][y]=' ';
                    } 
                    if(x+2 < 10 && vila[x+2][y]=='*'){
                        vila[x+2][y]='*';
                    }else if(x+2 < 10){
                        vila[x+2][y]=' ';
                    }
                    if(x+3 < 10 && vila[x+3][y]=='*'){
                        vila[x+3][y]='*'; 
                    }else if(x+3 < 10){
                        vila[x+3][y]=' ';
                    }
                    if(x+4 < 10 && vila[x+4][y]=='*'){
                        vila[x+4][y]='*'; 
                    }else if(x+4 < 10){
                        vila[x+4][y]=' ';
                    }
                }
                if(vila[x][y]=='>'){
                    if(y+1 < 10 && vila[x][y+1]=='*'){
                        vila[x][y+1]='*';
                    }else if(y+1 < 10){    
                        vila[x][y+1]=' ';
                    } 
                    if(y+2 < 10 && vila[x][y+2]=='*'){
                        vila[x][y+2]='*';
                    }else if(y+2 < 10){
                        vila[x][y+2]=' ';
                    }
                    if(y+3 < 10 && vila[x][y+3]=='*'){
                        vila[x][y+3]='*'; 
                    }else if(y+3 < 10){
                        vila[x][y+3]=' ';
                    }
                    if(y+4 < 10 && vila[x][y+4]=='*'){
                        vila[x][y+4]='*'; 
                    }else if(y+4 < 10){
                        vila[x][y+4]=' ';
                    }
                }
                if(vila[x][y]=='<'){
                    if(y-1 >= 0 && vila[x][y-1]=='*'){
                        vila[x][y-1]='*';
                    }else if(y-1 >= 0){    
                        vila[x][y-1]=' ';
                    } 
                    if(y-2 >= 0 && vila[x][y-2]=='*'){
                        vila[x][y-2]='*';
                    }else if(y-2 >= 0){
                        vila[x][y-2]=' ';
                    }
                    if(y-3 >= 0 && vila[x][y-3]=='*'){
                        vila[x][y-3]='*'; 
                    }else if(y-3 >= 0){
                        vila[x][y-3]=' ';
                    }
                    if(y-4 >= 0 && vila[x][y-4]=='*'){
                        vila[x][y-4]='*'; 
                    }else if(y-4 >= 0){
                        vila[x][y-4]=' ';
                    }    
                }
            }

            else if (arma_atual == 'C') {
                // Diagonais
                if(x+1 < 10 && y-1 >= 0 && vila[x+1][y-1]=='*'){
                    vila[x+1][y-1]='*';
                }else if(x+1 < 10 && y-1 >= 0){
                    vila[x+1][y-1]=' ';
                }
                if(x-1 >= 0 && y-1 >= 0 && vila[x-1][y-1]=='*'){
                    vila[x-1][y-1]='*';
                }else if(x-1 >= 0 && y-1 >= 0){
                    vila[x-1][y-1]=' ';
                }
                if(x+1 < 10 && y+1 < 10 && vila[x+1][y+1]=='*'){
                    vila[x+1][y+1]='*';
                }else if(x+1 < 10 && y+1 < 10){
                    vila[x+1][y+1]=' ';
                }
                if(x-1 >= 0 && y+1 < 10 && vila[x-1][y+1]=='*'){
                    vila[x-1][y+1]='*';
                }else if(x-1 >= 0 && y+1 < 10){
                    vila[x-1][y+1]=' ';
                }
                // Reto
                if(x+1 < 10 && vila[x+1][y]=='*'){
                    vila[x+1][y]='*';
                }else if(x+1 < 10){
                    vila[x+1][y]=' ';
                }
                if(x-1 >= 0 && vila[x-1][y]=='*'){
                    vila[x-1][y]='*';
                }else if(x-1 >= 0){
                    vila[x-1][y]=' ';
                }
                if(y+1 < 10 && vila[x][y+1]=='*'){
                    vila[x][y+1]='*';
                }else if(y+1 < 10){
                    vila[x][y+1]=' ';
                }
                if(y-1 >= 0 && vila[x][y-1]=='*'){
                    vila[x][y-1]='*';
                }else if(y-1 >= 0){
                    vila[x][y-1]=' ';
                }
            }
            
            if(vila[botX][botY] == ' ' && vida_bot > 0){
                vida_bot--;
                vila[botX][botY] = ' ';
            }
        
        }
		
        if(x+1 < 10 && vila[x+1][y] == vila[4][4]){ vila[4][4]='H'; }
        if(x-1 >= 0 && vila[x-1][y] == vila[4][4]){ vila[4][4]='H'; }
        if(y+1 < 10 && vila[x][y+1] == vila[4][4]){ vila[4][4]='H'; }
        if(y-1 >= 0 && vila[x][y-1] == vila[4][4]){ vila[4][4]='H'; }


        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                printf("%c ", vila[i][j]);
            }
            printf("\n");
        }
        
    }
    
    fase_teste:
    if(vida_bot < 1){ vida_bot = 1; }
    if(vida_botP < 1){ vida_botP = 1; }

		
	x = 7; 
    y = 6; 
    botX = 6; botY = 6;
    botXP = 5; botYP = 5;
    
    vila1[x][y] = '>';
    vila1[botX][botY] = 'X';
    vila1[botXP][botYP] = 'Y';
    vila1[8][5] = '#';
    
    for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			printf("%c ", vila1[i][j]);
		}
		printf("\n");
	}
	
 	vila1[x][y] = '>';
        int chave=0;
 	
    while(1)
    {
        input = getch();
        limpar();
        
        if(input == 's' || input == 'S'){ // Pra baixo
            if(x < 9){
            
                if(vila1[x+1][y] != '*' && vila1[x+1][y] != 'D' && vila1[x+1][y] != '/' && vila1[x+1][y] != '`' && vila1[x+1][y] != 'H'&&vila1[x+1][y] != 'k'){ 
                    	if(vila1[x+1][y]=='@'){
					chave=chave+1;
				          }
					vila1[x][y] = ' ';
                    x = x + 1;
                    vila1[x][y] = 'v';
                }
            }
        }else if(input == 'w' || input == 'W'){ // Pra Cima
            if(x > 0){
            	
                if(vila1[x-1][y] != '*' && vila1[x-1][y] != 'D' && vila1[x-1][y] != '/' && vila1[x-1][y] != '`' && vila1[x-1][y] != 'H' &&vila1[x-1][y] != 'k'){ 
                    	if(vila1[x-1][y]=='@'){
					chave=chave+1;
				}
					vila1[x][y] = ' ';
                    x = x - 1;
                    vila1[x][y] = '^';
                }
            }
        }else if(input == 'd' || input == 'D'){ // Pra direita
            if(y < 9){
            	
                if(vila1[x][y+1] != '*' && vila1[x][y+1] != 'D' && vila1[x][y+1] != '/' && vila1[x][y+1] != '`' && vila1[x][y+1] != 'H' &&vila1[x][y+1] != 'k'){ 
                   	if(vila1[x][y+1]=='@'){
					chave=chave+1;
				}
				    vila1[x][y] = ' ';
                    y = y + 1;
                    vila1[x][y] = '>';
                }
            }
        }else if(input == 'a' || input == 'A'){ // Pra esquerda
            if(y > 0){
            	
                if(vila1[x][y-1] != '*' && vila1[x][y-1] != 'D' && vila1[x][y-1] != '/' && vila1[x][y-1] != '`' && vila1[x][y-1] != 'H' && vila1[x][y-1] != 'k'){ 
                    	if(vila1[x][y-1]=='@'){
					chave=chave+1;
				}
					vila1[x][y] = ' ';
                    y = y - 1;       
                    vila1[x][y] = '<';
                }
            }
        }
        
      
        if(vila1[x][y] != vila1[PIx][PIy]){	
		 vila1[PIx][PIy] = 'D';
		}
		//porta
           if(vila1[x][y]==vila1[8][8]){
			   chave++;
		   }
   if(vila1[x][y]== vila1[2][5]){
   	if(vila1 [x][y]=='^'){
	   if(vila1[x-1][y]==vila1[1][5]){
		   if(chave==1){
			   vila1[1][5]='=';
		   }
	   }
	   }
   }
  		 
        if (input == 'i' || input == 'I') {
           
            if (vila1[x+1][y] == 'H' || vila1[x-1][y] == 'H' || vila1[x][y+1] == 'H' || vila1[x][y-1] == 'H') {
                
                system("cls");
                
                printf("--- npc buxa ---\n");
                printf("escolhe ae mano\n");
                printf("1: Espada\n");
                printf("2: Arco\n");
                printf("3: Cajado\n");
                printf("-----------------\n");
                printf("Escolha o numero da arma para selecionar.\nCaso nao queira digite qualquer tecla.");
                char escolha = getch(); 

                if (escolha == '1') {
                    arma_atual = 'E';
                    printf("\n\nVoce equipou a ESPADA!");
                } 
                else if (escolha == '2') {
                    arma_atual = 'A';
                    printf("\n\nVoce equipou o ARCO!");
                } 
                else if (escolha == '3') {
                    arma_atual = 'C';
                    printf("\n\nVoce equipou o CAJADO!");
                }

                printf("\nPressione qualquer tecla para fechar o menu");
                getch(); 
                system("cls");
            } 
        } 
        
        if(vida_bot > 0){
    int tentativa = 0;
    while(tentativa < 3)
    {
        direcao = rand() % 4; 
        tentativa++;
        
        if(direcao == 0){ // Pra cima
            
            if(botX > 0 && (vila1[botX-1][botY] == ' ' || vila1[botX-1][botY] == '>' || vila1[botX-1][botY] == '<' || vila1[botX-1][botY] == '^' || vila1[botX-1][botY] == 'v')){
                vila1[botX][botY] = ' ';
                botX--;
                break;
            }
        }
        else if(direcao == 1){ // Pra baixo
            if(botX < 9 && (vila1[botX+1][botY] == ' ' || vila1[botX+1][botY] == '>' || vila1[botX+1][botY] == '<' || vila1[botX+1][botY] == '^' || vila1[botX+1][botY] == 'v')){
                vila1[botX][botY] = ' ';
                botX++;
                break;
            }
        }
        else if(direcao == 2){ // Pra esquerda
            if(botY > 0 && (vila1[botX][botY-1] == ' ' || vila1[botX][botY-1] == '>' || vila1[botX][botY-1] == '<' || vila1[botX][botY-1] == '^' || vila1[botX][botY-1] == 'v')){
                vila1[botX][botY] = ' ';
                botY--;
                break;
            }
        }
        else if(direcao == 3){ // Pra direita
            if(botY < 9 && (vila1[botX][botY+1] == ' ' || vila1[botX][botY+1] == '>' || vila1[botX][botY+1] == '<' || vila1[botX][botY+1] == '^' || vila1[botX][botY+1] == 'v')){
                vila1[botX][botY] = ' ';
                botY++;
                break;
            }
        }
    }
    vila1[botX][botY] = 'X';
}
    
		if(vida_bot > 0 && x == botX && y == botY){
    		vida--;
    	if(vida == 0){
        	system("cls");
        	printf("voce perdeu...\n");
        	goto morte;
    	}
    	
    	if(vida_bot > 0 && x == botX && y == botY){
        	morte_jogador:
			vida--;
			if(vida == 0){
    			system("cls");
				printf("voce perdeu...\n");
				goto morte;
			}
			
			vila[x][y] = ' ';
            vila[botX][botY] = ' ';
            
        	system("cls"); 
			printf("Voce morreu, pressione qualquer tecla para tentar novamente");			
			
			getch();
			system("cls");
			
			goto vila;
		}
    
    vila1[x][y] = ' ';
    vila1[botX][botY] = ' ';
    
    system("cls"); 
    printf("Voce morreu, pressione qualquer tecla para tentar novamente");            
    
    getch();
    system("cls");
    
    goto vila;
}
        

        if(input == 'o' || input == 'O') {
           
//espada
            if (arma_atual == 'E') {
                if(vila1[x][y]=='v'){
                    if(x+1 < 10 && vila1[x+1][y]=='*'){
                        vila1[x+1][y]='*';
                    }else if(x+1 < 10 && vila1[x+1][y]=='@'){
						vila1[x+1][y]='@';
					}else  if(x+1 < 10 && vila1[x+1][y]=='D'){
						vila1[x+1][y]='D';
					
					}else if(x+1 < 10 && vila1[x+1][y]=='#'){
						vila1[x+1][y]='#'; 
					}else if(x+1 < 10 && vila1[x+1][y]=='o'){
						vila1[x+1][y]='o';
					}else if(x+1 < 10 && vila1[x+1][y]!='*'){
                        vila1[x+1][y]=' ';
                    } 
                     if(x+2 < 10 && vila1[x+2][y]=='*'){
                        vila1[x+2][y]='*';
                    }else if(x+2 < 10 && vila1[x+2][y]=='@'){
						vila1[x+2][y]='@';
					}else  if(x+2 < 10 && vila1[x+2][y]=='D'){
						vila1[x+2][y]='D';
					}else if(x+2 < 10 && vila1[x+2][y]=='#'){
						vila1[x+2][y]='#'; 
					}else if(x+2 < 10 && vila1[x+2][y]=='o'){
						vila1[x+2][y]='o';
					}else if(x+2 < 10 && vila1[x+2][y]!='*'){
                        vila1[x+2][y]=' ';
					}
                     if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='*'){
                        vila1[x+1][y+1]='*';
                    }else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='@'){
						vila1[x+1][y+1]='@';
					} else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='D'){
						vila1[x+1][y+1]='D';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='#'){
						vila1[x+1][y+1]='#';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='o'){
						vila1[x+1][y+1]='o';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]!='*'){
                        vila1[x+1][y+1]=' ';
                    } 
                    
                    if(x+2 < 10 && y+1 < 10 && vila1[x+2][y+1]=='*'){
                        vila1[x+2][y+1]='*';
                    }else if(x+2 < 10 && y+1 < 10 && vila1[x+2][y+1]=='@'){
						vila1[x+2][y+1]='@';
					} else if(x+2 < 10 && y+1 < 10 && vila1[x+2][y+1]=='D'){
						vila1[x+2][y+1]='D';
					}else if(x+2 < 10 && y+1 < 10 && vila1[x+2][y+1]=='#'){
						vila1[x+2][y+1]='#';
					}else if(x+2 < 10 && y+1 < 10 && vila1[x+2][y+1]=='o'){
						vila1[x+2][y+1]='o';
					}else if(x+2 < 10 && y+1 < 10 && vila1[x+2][y+1]!='*'){
                        vila1[x+2][y+1]=' ';
                    } 
                    
                    if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='*'){
                        vila1[x+1][y-1]='*';
                    }else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='@'){
						vila1[x+1][y-1]='@';
					} else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='D'){
						vila1[x+1][y-1]='D';
					}else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='#'){
						vila1[x+1][y-1]='#';
					}else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='o'){
						vila1[x+1][y-1]='o';
					}else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]!='*'){
                        vila1[x+1][y-1]=' ';
                    } 
                    if(x+2 < 10 && y-1 >= 0 && vila1[x+2][y-1]=='*'){
                        vila1[x+2][y-1]='*';
                    }else if(x+2 < 10 && y-1 >= 0 && vila1[x+2][y-1]=='@'){
						vila1[x+2][y-1]='@';
					} else if(x+2 < 10 && y-1 >= 0 && vila1[x+2][y-1]=='D'){
						vila1[x+2][y-1]='D';
					}else if(x+2 < 10 && y-1 >= 0 && vila1[x+2][y-1]=='#'){
						vila1[x+2][y-1]='#';
					}else if(x+2 < 10 && y-1 >= 0 && vila1[x+2][y-1]=='o'){
						vila1[x+2][y-1]='o';
					}else if(x+2 < 10 && y-1 >= 0 && vila1[x+2][y-1]!='*'){
                        vila1[x+2][y-1]=' ';
                    } 
                }
                
                if(vila1[x][y]=='>'){
                     if(y+1 < 10 && vila1[x][y+1]=='*'){
                        vila1[x][y+1]='*';
                    }else if(y+1 < 10 && vila1[x][y+1]=='@'){
						vila1[x][y+1]='@';
					}else  if(y+1 < 10 && vila1[x][y+1]=='D'){
						vila1[x][y+1]='D';
					}else if(y+1 < 10 && vila1[x][y+1]=='#'){
						vila1[x][y+1]='#'; 
					}else if(y+1 < 10 && vila1[x][y+1]=='o'){
						vila1[x][y+1]='o';
					}else if(y+1 < 10 && vila1[x][y+1]!='*'){
                        vila1[x][y+1]=' ';	
						}
                    if(y+2 < 10 && vila1[x][y+2]=='*'){
                        vila1[x][y+2]='*';
                    }else if(y+2 < 10 && vila1[x][y+2]=='@'){
						vila1[x][y+2]='@';
					}else  if(y+2 < 10 && vila1[x][y+2]=='D'){
						vila1[x][y+2]='D';
					
					}else if(y+2 < 10 && vila1[x][y+2]=='#'){
						vila1[x][y+2]='#'; 
					}else if(y+2 < 10 && vila1[x][y+2]=='o'){
						vila1[x][y+2]='o';
					}else if(y+2 < 10 && vila1[x][y+2]!='*'){
                        vila1[x][y+2]=' ';
                    } 
                    
                     if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='*'){
                        vila1[x+1][y+1]='*';
                    }else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='@'){
						vila1[x+1][y+1]='@';
					} else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='D'){
						vila1[x+1][y+1]='D';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='#'){
						vila1[x+1][y+1]='#';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='o'){
						vila1[x+1][y+1]='o';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]!='*'){
                        vila1[x+1][y+1]=' ';
                    } 
                      if(x+1 < 10 && y+2 < 10 && vila1[x+1][y+2]=='*'){
                        vila1[x+1][y+2]='*';
                    }else if(x+1 < 10 && y+2 < 10 && vila1[x+1][y+2]=='@'){
						vila1[x+1][y+2]='@';
					} else if(x+1 < 10 && y+2 < 10 && vila1[x+1][y+2]=='D'){
						vila1[x+1][y+2]='D';
					}else if(x+1 < 10 && y+2 < 10 && vila1[x+1][y+2]=='#'){
						vila1[x+1][y+2]='#';
					}else if(x+1 < 10 && y+2 < 10 && vila1[x+1][y+2]=='o'){
						vila1[x+1][y+2]='o';
					}else if(x+1 < 10 && y+2 < 10 && vila1[x+1][y+2]!='*'){
                        vila1[x+1][y+2]=' ';
                    } 
                    
                    if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='*'){
                        vila1[x-1][y+1]='*';
                    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='@'){
						vila1[x-1][y+1]='@';
					}else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='D'){
						vila1[x-1][y+1]='D';
				    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='#'){
						vila1[x-1][y+1]='#';
			     	}else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='o'){
						vila1[x-1][y+1]='o';
				    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]!='*'){
                        vila1[x-1][y+1]=' ';
                    } 
                    if(x-1 >= 0 && y+2 < 10 && vila1[x-1][y+2]=='*'){
                        vila1[x-1][y+2]='*';
                    }else if(x-1 >= 0 && y+2 < 10 && vila1[x-1][y+2]=='@'){
						vila1[x-1][y+2]='@';
					}else if(x-1 >= 0 && y+2 < 10 && vila1[x-1][y+2]=='D'){
						vila1[x-1][y+2]='D';
				    }else if(x-1 >= 0 && y+2 < 10 && vila1[x-1][y+2]=='#'){
						vila1[x-1][y+2]='#';
			     	}else if(x-1 >= 0 && y+2 < 10 && vila1[x-1][y+2]=='o'){
						vila1[x-1][y+2]='o';
				    }else if(x-1 >= 0 && y+2 < 10 && vila1[x-1][y+2]!='*'){
                        vila1[x-1][y+2]=' ';
                    } 
                }
                
                if(vila1[x][y]=='<'){
                    if(y-1 >= 0 && vila1[x][y-1]=='*'){
                        vila1[x][y-1]='*';
                    }else  if(y-1 >= 0 && vila1[x][y-1]=='@'){
						 vila1[x][y-1]='@';
					}else 
					if(y-1 >= 0 && vila1[x][y-1]=='D'){
						 vila1[x][y-1]='D';
					}else
					if(y-1 >= 0 && vila1[x][y-1]=='#'){
						 vila1[x][y-1]='#';
					}else 
					if(y-1 >= 0 && vila1[x][y-1]=='o'){
						 vila1[x][y-1]='o';
					}else if(y-1 >= 0 && vila1[x][y-1]!='*'){
                        vila1[x][y-1]=' ';
                    } 
                    if(y-2 >= 0 && vila1[x][y-2]=='*'){
                        vila1[x][y-2]='*';
                    }else  if(y-2 >= 0 && vila1[x][y-2]=='@'){
						 vila1[x][y-2]='@';
					}else 	if(y-2 >= 0 && vila1[x][y-2]=='D'){
						 vila1[x][y-2]='D';
					}else if(y-2 >= 0 && vila1[x][y-2]=='#'){
						 vila1[x][y-2]='#';
					}else if(y-2 >= 0 && vila1[x][y-2]=='o'){
						 vila1[x][y-2]='o';
					}else if(y-2 >= 0 && vila1[x][y-2]!='*'){
                        vila1[x][y-2]=' ';
                    } 
				
					
					
                    
                    if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='*'){
                        vila1[x+1][y-1]='*';
                    }else  if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='@'){
						 vila1[x+1][y-1]='@';
					}else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]!='*'){
                        vila1[x+1][y-1]=' ';
                    }
                    if(x+1 < 10 && y-2 >= 0 && vila1[x+1][y-2]=='*'){
                        vila1[x+1][y-2]='*';
                    }else if(x+1 < 10 && y-2 >= 0 && vila1[x+1][y-2]=='@'){
						 vila1[x+1][y-2]='@';
					}else	if(x+1 < 10 && y-2 >= 0 && vila1[x+1][y-2]!='*'){
                        vila1[x+1][y-2]=' ';
                    }

                    if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='*'){
                        vila1[x-1][y-1]='*';
                    }else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='@'){
						vila1[x-1][y-1]='@';
					} else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='D'){
						vila1[x-1][y-1]='D';
					}else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='#'){
						vila1[x-1][y-1]='#';
					}else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='o'){
						vila1[x-1][y-1]='o';
					}else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]!='*'){
                        vila1[x-1][y-1]=' ';
                    } 
                   if(x-1 >= 0 && y-2 >= 0 && vila1[x-1][y-2]=='*'){
                        vila1[x-1][y-2]='*';
                    }else if(x-1 >= 0 && y-2 >= 0 && vila1[x-1][y-2]=='@'){
						vila1[x-1][y-2]='@';
					} else if(x-1 >= 0 && y-2 >= 0 && vila1[x-1][y-2]=='D'){
						vila1[x-1][y-2]='D';
					}else if(x-1 >= 0 && y-2 >= 0 && vila1[x-1][y-2]=='#'){
						vila1[x-1][y-2]='#';
					}else if(x-1 >= 0 && y-2 >= 0 && vila1[x-1][y-2]=='o'){
						vila1[x-1][y-2]='o';
					}else if(x-1 >= 0 && y-2 >= 0 && vila1[x-1][y-2]!='*'){
                        vila1[x-1][y-2]=' ';
                    } 
                }
                
                if(vila1[x][y]=='^'){
                     if(x-1 >= 0 && vila1[x-1][y]=='*'){
                        vila1[x-1][y]='*';
                    }else  if(x-1 >= 0 && vila1[x-1][y]=='@'){
						 vila1[x-1][y]='@';
					}else 
					if(x-1 >= 0 && vila1[x-1][y]=='D'){
						 vila1[x-1][y]='D';
					}else
					if(x-1 >= 0 && vila1[x-1][y]=='#'){
						 vila1[x-1][y]='#';
					}else 
					if(x-1 >= 0 && vila1[x-1][y]=='o'){
						 vila1[x-1][y]='o';
					}else if(x-1 >= 0 && vila1[x-1][y]!='*'){
                        vila1[x-1][y]=' ';
                    } 
                    
                     if(x-2 >= 0 && vila1[x-2][y]=='*'){
                        vila1[x-2][y]='*';
                    }else  if(x-2 >= 0 && vila1[x-2][y]=='@'){
						 vila1[x-2][y]='@';
					}else 
					if(x-2 >= 0 && vila1[x-2][y]=='D'){
						 vila1[x-2][y]='D';
					}else
					if(x-2 >= 0 && vila1[x-2][y]=='#'){
						 vila1[x-2][y]='#';
					}else 
					if(x-2 >= 0 && vila1[x-2][y]=='o'){
						 vila1[x-2][y]='o';
					}else if(x-2 >= 0 && vila1[x-2][y]!='*'){
                        vila1[x-2][y]=' ';
                    } 
                    if(x-2 >= 0 && y+1 < 10 && vila1[x-2][y+1]=='*'){
                        vila1[x-2][y+1]='*';
                    }else  if(x-2 >= 0 && y+1 < 10 && vila1[x-2][y+1]=='@'){
						  vila1[x-2][y+1]='@';
					}else if(x-2 >= 0 && y+1 < 10 && vila1[x-2][y+1]=='D'){
						  vila1[x-2][y+1]='D';
					}else if(x-2 >= 0 && y+1 < 10 && vila1[x-2][y+1]=='#'){
						  vila1[x-2][y+1]='#';
					}else  if(x-2 >= 0 && y+1 < 10 && vila1[x-2][y+1]=='o'){
						  vila1[x-2][y+1]='o';
					}else if(x-2 >= 0 && y+1 < 10 && vila1[x-2][y+1]!='*'){
                        vila1[x-2][y+1]=' ';
                    }
                    
                    if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='*'){
                        vila1[x-1][y-1]='*';
                    }else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='@'){
						  vila1[x-1][y-1]='@';
					}else  if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='D'){
						  vila1[x-1][y-1]='D';
					}else  if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='#'){
						  vila1[x-1][y-1]='#';
					}else  if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='o'){
						  vila1[x-1][y-1]='o';
					}else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]!='*'){
                        vila1[x-1][y-1]=' ';
                    } 
                    if(x-2 >= 0 && y-1 >= 0 && vila1[x-2][y-1]=='*'){
                        vila1[x-2][y-1]='*';
                    }else if(x-2 >= 0 && y-1 >= 0 && vila1[x-2][y-1]=='@'){
						  vila1[x-2][y-1]='@';
					}else  if(x-2 >= 0 && y-1 >= 0 && vila1[x-2][y-1]=='D'){
						  vila1[x-2][y-1]='D';
					}else  if(x-2 >= 0 && y-1 >= 0 && vila1[x-2][y-1]=='#'){
						  vila1[x-2][y-1]='#';
					}else  if(x-2 >= 0 && y-1 >= 0 && vila1[x-2][y-1]=='o'){
						  vila1[x-2][y-1]='o';
					}else if(x-2 >= 0 && y-1 >= 0 && vila1[x-2][y-1]!='*'){
                        vila1[x-2][y-1]=' ';
                    } 
                 if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='*'){
                        vila1[x-1][y+1]='*';
                    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='@'){
						vila1[x-1][y+1]='@';
					}else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='D'){
						vila1[x-1][y+1]='D';
				    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='#'){
						vila1[x-1][y+1]='#';
			     	}else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='o'){
						vila1[x-1][y+1]='o';
				    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]!='*'){
                        vila1[x-1][y+1]=' ';
                    } 
                }
            }

			//arco
            else if (arma_atual == 'A') {
                if(vila1[x][y]=='^'){
                    if(x-1 >= 0 && vila1[x-1][y]=='*'){
                        vila1[x-1][y]='*';
                    }else  if(x-1 >= 0 && vila1[x-1][y]=='@'){
                        vila1[x-1][y]='@';
                    }else  if(x-1 >= 0 && vila1[x-1][y]=='D'){
                        vila1[x-1][y]='D';
                    }else  if(x-1 >= 0 && vila1[x-1][y]=='#'){
                        vila1[x-1][y]='#';
                    }else  if(x-1 >= 0 && vila1[x-1][y]=='o'){
                        vila1[x-1][y]='o';
                    }else if(x-1 >= 0 && vila1[x-1][y]!='*'){    
                        vila1[x-1][y]=' ';
                    } 
                     if(x-2 >= 0 && vila1[x-2][y]=='*'){
                        vila1[x-2][y]='*';
                    }else  if(x-2 >= 0 && vila1[x-2][y]=='@'){
                        vila1[x-2][y]='@';
                    }else  if(x-2 >= 0 && vila1[x-2][y]=='D'){
                        vila1[x-2][y]='D';
                    }else  if(x-2 >= 0 && vila1[x-2][y]=='#'){
                        vila1[x-2][y]='#';
                    }else  if(x-2 >= 0 && vila1[x-2][y]=='o'){
                        vila1[x-2][y]='o';
                    }else if(x-2 >= 0 && vila1[x-2][y]!='*'){    
                        vila1[x-2][y]=' ';
                    } 
                    if(x-3 >= 0 && vila1[x-3][y]=='*'){
                        vila1[x-3][y]='*';
                    }else  if(x-3 >= 0 && vila1[x-3][y]=='@'){
                        vila1[x-3][y]='@';
                    }else  if(x-3 >= 0 && vila1[x-3][y]=='D'){
                        vila1[x-3][y]='D';
                    }else  if(x-3 >= 0 && vila1[x-3][y]=='#'){
                        vila1[x-3][y]='#';
                    }else  if(x-3 >= 0 && vila1[x-3][y]=='o'){
                        vila1[x-3][y]='o';
                    }else if(x-3 >= 0 && vila1[x-3][y]!='*'){    
                        vila1[x-3][y]=' ';
                    } 
                   if(x-4 >= 0 && vila1[x-4][y]=='*'){
                        vila1[x-4][y]='*';
                    }else  if(x-4 >= 0 && vila1[x-4][y]=='@'){
                        vila1[x-4][y]='@';
                    }else  if(x-4 >= 0 && vila1[x-4][y]=='D'){
                        vila1[x-4][y]='D';
                    }else  if(x-4 >= 0 && vila1[x-4][y]=='#'){
                        vila1[x-4][y]='#';
                    }else  if(x-4 >= 0 && vila1[x-4][y]=='o'){
                        vila1[x-4][y]='o';
                    }else if(x-4 >= 0 && vila1[x-4][y]!='*'){    
                        vila1[x-4][y]=' ';
                    } 
                }
                if(vila1[x][y]=='v'){
                    if(x+1 < 10 && vila1[x+1][y]=='*'){
                        vila1[x+1][y]='*';
                    }else  if(x+1 < 10 && vila1[x+1][y]=='@'){
                        vila1[x+1][y]='@';
                    }else  if(x+1 < 10 && vila1[x+1][y]=='D'){
                        vila1[x+1][y]='D';
                    }else  if(x+1 < 10 && vila1[x+1][y]=='#'){
                        vila1[x+1][y]='#';
                    }else  if(x+1 < 10 && vila1[x+1][y]=='o'){
                        vila1[x+1][y]='o';
                    }else if(x+1 < 10 && vila1[x+1][y]!='*'){    
                        vila1[x+1][y]=' ';
                    } 
                    if(x+2 < 10 && vila1[x+2][y]=='*'){
                        vila1[x+2][y]='*';
                    }else  if(x+2 < 10 && vila1[x+2][y]=='@'){
                        vila1[x+2][y]='@';
                    }else  if(x+2 < 10 && vila1[x+2][y]=='D'){
                        vila1[x+2][y]='D';
                    }else  if(x+2 < 10 && vila1[x+2][y]=='#'){
                        vila1[x+2][y]='#';
                    }else  if(x+2 < 10 && vila1[x+2][y]=='o'){
                        vila1[x+2][y]='o';
                    }else if(x+2 < 10 && vila1[x+2][y]!='*'){    
                        vila1[x+2][y]=' ';
                    } 
                     if(x+3 < 10 && vila1[x+3][y]=='*'){
                        vila1[x+3][y]='*';
                    }else  if(x+3 < 10 && vila1[x+3][y]=='@'){
                        vila1[x+3][y]='@';
                    }else  if(x+3 < 10 && vila1[x+3][y]=='D'){
                        vila1[x+3][y]='D';
                    }else  if(x+3 < 10 && vila1[x+3][y]=='#'){
                        vila1[x+3][y]='#';
                    }else  if(x+3 < 10 && vila1[x+3][y]=='o'){
                        vila1[x+3][y]='o';
                    }else if(x+3 < 10 && vila1[x+3][y]!='*'){    
                        vila1[x+3][y]=' ';
                    } 
                    if(x+4 < 10 && vila1[x+4][y]=='*'){
                        vila1[x+4][y]='*';
                    }else  if(x+4 < 10 && vila1[x+4][y]=='@'){
                        vila1[x+4][y]='@';
                    }else  if(x+4 < 10 && vila1[x+4][y]=='D'){
                        vila1[x+4][y]='D';
                    }else  if(x+4 < 10 && vila1[x+4][y]=='#'){
                        vila1[x+4][y]='#';
                    }else  if(x+4 < 10 && vila1[x+4][y]=='o'){
                        vila1[x+4][y]='o';
                    }else if(x+4 < 10 && vila1[x+4][y]!='*'){    
                        vila1[x+4][y]=' ';
                    } 
                }
                if(vila1[x][y]=='>'){
                    if(y+1 < 10 && vila1[x][y+1]=='*'){
                        vila1[x][y+1]='*';
                    }else  if(y+1 < 10 && vila1[x][y+1]=='@'){
                        vila1[x][y+1]='@';
                    }else  if(y+1 < 10 && vila1[x][y+1]=='D'){
                        vila1[x][y+1]='D';
                    }else  if(y+1 < 10 && vila1[x][y+1]=='#'){
                        vila1[x][y+1]='#';
                    }else  if(y+1 < 10 && vila1[x][y+1]=='o'){
                        vila1[x][y+1]='o';
                    }else if(y+1 < 10 && vila1[x][y+1]!='*'){    
                        vila1[x][y+1]=' ';
                    } 
                    if(y+2 < 10 && vila1[x][y+2]=='*'){
                        vila1[x][y+2]='*';
                    }else  if(y+2 < 10 && vila1[x][y+2]=='@'){
                        vila1[x][y+2]='@';
                    }else  if(y+2 < 10 && vila1[x][y+2]=='D'){
                        vila1[x][y+2]='D';
                    }else  if(y+2 < 10 && vila1[x][y+2]=='#'){
                        vila1[x][y+2]='#';
                    }else  if(y+2 < 10 && vila1[x][y+2]=='o'){
                        vila1[x][y+2]='o';
                    }else if(y+2 < 10 && vila1[x][y+2]!='*'){    
                        vila1[x][y+2]=' ';
                    } 
                    if(y+3 < 10 && vila1[x][y+3]=='*'){
                        vila1[x][y+3]='*';
                    }else  if(y+3 < 10 && vila1[x][y+3]=='@'){
                        vila1[x][y+3]='@';
                    }else  if(y+3 < 10 && vila1[x][y+3]=='D'){
                        vila1[x][y+3]='D';
                    }else  if(y+3 < 10 && vila1[x][y+3]=='#'){
                        vila1[x][y+3]='#';
                    }else  if(y+3 < 10 && vila1[x][y+3]=='o'){
                        vila1[x][y+3]='o';
                    }else if(y+3 < 10 && vila1[x][y+3]!='*'){    
                        vila1[x][y+3]=' ';
                    } 
                    if(y+4 < 10 && vila1[x][y+4]=='*'){
                        vila1[x][y+4]='*';
                    }else  if(y+4 < 10 && vila1[x][y+4]=='@'){
                        vila1[x][y+4]='@';
                    }else  if(y+4 < 10 && vila1[x][y+4]=='D'){
                        vila1[x][y+4]='D';
                    }else  if(y+4 < 10 && vila1[x][y+4]=='#'){
                        vila1[x][y+4]='#';
                    }else  if(y+4 < 10 && vila1[x][y+4]=='o'){
                        vila1[x][y+4]='o';
                    }else if(y+4 < 10 && vila1[x][y+4]!='*'){    
                        vila1[x][y+4]=' ';
                    } 
                }
                if(vila1[x][y]=='<'){
                    if(y-1 >= 0 && vila1[x][y-1]=='*'){
                        vila1[x][y-1]='*';
                    }else  if(y-1 >= 0 && vila1[x][y-1]=='@'){
                        vila1[x][y-1]='@';
                    }else  if(y-1 >= 0 && vila1[x][y-1]=='D'){
                        vila1[x][y-1]='D';
                    }else  if(y-1 >= 0 && vila1[x][y-1]=='#'){
                        vila1[x][y-1]='#';
                    }else  if(y-1 >= 0 && vila1[x][y-1]=='o'){
                        vila1[x][y-1]='o';
                    }else if(y-1 >= 0 && vila1[x][y-1]!='*'){    
                        vila1[x][y-1]=' ';
                    } 
                     if(y-2 >= 0 && vila1[x][y-2]=='*'){
                        vila1[x][y-2]='*';
                    }else  if(y-2 >= 0 && vila1[x][y-2]=='@'){
                        vila1[x][y-2]='@';
                    }else  if(y-2 >= 0 && vila1[x][y-2]=='D'){
                        vila1[x][y-2]='D';
                    }else  if(y-2 >= 0 && vila1[x][y-2]=='#'){
                        vila1[x][y-1]='#';
                    }else  if(y-2 >= 0 && vila1[x][y-2]=='o'){
                        vila1[x][y-2]='o';
                    }else if(y-2 >= 0 && vila1[x][y-2]!='*'){    
                        vila1[x][y-2]=' ';
                    } 
                     if(y-3 >= 0 && vila1[x][y-3]=='*'){
                        vila1[x][y-3]='*';
                    }else  if(y-3 >= 0 && vila1[x][y-3]=='@'){
                        vila1[x][y-3]='@';
                    }else  if(y-3 >= 0 && vila1[x][y-3]=='D'){
                        vila1[x][y-3]='D';
                    }else  if(y-3 >= 0 && vila1[x][y-3]=='#'){
                        vila1[x][y-3]='#';
                    }else  if(y-3 >= 0 && vila1[x][y-3]=='o'){
                        vila1[x][y-3]='o';
                    }else if(y-3 >= 0 && vila1[x][y-3]!='*'){    
                        vila1[x][y-3]=' ';
                    } 
                     if(y-4 >= 0 && vila1[x][y-4]=='*'){
                        vila1[x][y-4]='*';
                    }else  if(y-4 >= 0 && vila1[x][y-4]=='@'){
                        vila1[x][y-4]='@';
                    }else  if(y-4 >= 0 && vila1[x][y-4]=='D'){
                        vila1[x][y-4]='D';
                    }else  if(y-4 >= 0 && vila1[x][y-4]=='#'){
                        vila1[x][y-4]='#';
                    }else  if(y-4 >= 0 && vila1[x][y-4]=='o'){
                        vila1[x][y-4]='o';
                    }else if(y-4 >= 0 && vila1[x][y-4]!='*'){    
                        vila1[x][y-4]=' ';
                    } 
                }
            }
               //cajado
            else if (arma_atual == 'C') {
                // Diagonais
                
                if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='*'){
                        vila1[x+1][y-1]='*';
                    }else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='@'){
						vila1[x+1][y-1]='@';
					} else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='D'){
						vila1[x+1][y-1]='D';
					}else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='#'){
						vila1[x+1][y-1]='#';
					}else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]=='o'){
						vila1[x+1][y-1]='o';
					}else if(x+1 < 10 && y-1 >= 0 && vila1[x+1][y-1]!='*'){
                        vila1[x+1][y-1]=' ';
                    } 
                 if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='*'){
                        vila1[x-1][y-1]='*';
                    }else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='@'){
						vila1[x-1][y-1]='@';
					} else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='D'){
						vila1[x-1][y-1]='D';
					}else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='#'){
						vila1[x-1][y-1]='#';
					}else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]=='o'){
						vila1[x-1][y-1]='o';
					}else if(x-1 >= 0 && y-1 >= 0 && vila1[x-1][y-1]!='*'){
                        vila1[x-1][y-1]=' ';
                    } 
                 if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='*'){
                        vila1[x+1][y+1]='*';
                    }else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='@'){
						vila1[x+1][y+1]='@';
					} else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='D'){
						vila1[x+1][y+1]='D';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='#'){
						vila1[x+1][y+1]='#';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]=='o'){
						vila1[x+1][y+1]='o';
					}else if(x+1 < 10 && y+1 < 10 && vila1[x+1][y+1]!='*'){
                        vila1[x+1][y+1]=' ';
                    } 
                if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='*'){
                        vila1[x-1][y+1]='*';
                    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='@'){
						vila1[x-1][y+1]='@';
					}else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='D'){
						vila1[x-1][y+1]='D';
				    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='#'){
						vila1[x-1][y+1]='#';
			     	}else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]=='o'){
						vila1[x-1][y+1]='o';
				    }else if(x-1 >= 0 && y+1 < 10 && vila1[x-1][y+1]!='*'){
                        vila1[x-1][y+1]=' ';
                    } 
                // Reto
               if(x+1 < 10 && vila1[x+1][y]=='*'){
                        vila1[x+1][y]='*';
                    }else if(x+1 < 10 && vila1[x+1][y]=='@'){
						vila1[x+1][y]='@';
					}else  if(x+1 < 10 && vila1[x+1][y]=='D'){
						vila1[x+1][y]='D';
					
					}else if(x+1 < 10 && vila1[x+1][y]=='#'){
						vila1[x+1][y]='#'; 
					}else if(x+1 < 10 && vila1[x+1][y]=='o'){
						vila1[x+1][y]='o';
					}else if(x+1 < 10 && vila1[x+1][y]!='*'){
                        vila1[x+1][y]=' ';
                    } 
                if(x-1 >= 0 && vila1[x-1][y]=='*'){
                        vila1[x-1][y]='*';
                    }else  if(x-1 >= 0 && vila1[x-1][y]=='@'){
						 vila1[x-1][y]='@';
					}else 
					if(x-1 >= 0 && vila1[x-1][y]=='D'){
						 vila1[x-1][y]='D';
					}else
					if(x-1 >= 0 && vila1[x-1][y]=='#'){
						 vila1[x-1][y]='#';
					}else 
					if(x-1 >= 0 && vila1[x-1][y]=='o'){
						 vila1[x-1][y]='o';
					}else if(x-1 >= 0 && vila1[x-1][y]!='*'){
                        vila1[x-1][y]=' ';
                    } 
               if(y+1 < 10 && vila1[x][y+1]=='*'){
                        vila1[x][y+1]='*';
                    }else if(y+1 < 10 && vila1[x][y+1]=='@'){
						vila1[x][y+1]='@';
					}else  if(y+1 < 10 && vila1[x][y+1]=='D'){
						vila1[x][y+1]='D';
					}else if(y+1 < 10 && vila1[x][y+1]=='#'){
						vila1[x][y+1]='#'; 
					}else if(y+1 < 10 && vila1[x][y+1]=='o'){
						vila1[x][y+1]='o';
					}else if(y+1 < 10 && vila1[x][y+1]!='*'){
                        vila1[x][y+1]=' ';	
						}
                  if(y-1 >= 0 && vila1[x][y-1]=='*'){
                        vila1[x][y-1]='*';
                    }else  if(y-1 >= 0 && vila1[x][y-1]=='@'){
						 vila1[x][y-1]='@';
					}else 
					if(y-1 >= 0 && vila1[x][y-1]=='D'){
						 vila1[x][y-1]='D';
					}else
					if(y-1 >= 0 && vila1[x][y-1]=='#'){
						 vila1[x][y-1]='#';
					}else 
					if(y-1 >= 0 && vila1[x][y-1]=='o'){
						 vila1[x][y-1]='o';
					}else if(y-1 >= 0 && vila1[x][y-1]!='*'){
                        vila1[x][y-1]=' ';
                    } 
            }
        }
               

        if(x+1 < 10 && vila1[x+1][y] == vila1[4][4]){ vila1[4][4]='H'; }
        if(x-1 >= 0 && vila1[x-1][y] == vila1[4][4]){ vila1[4][4]='H'; }
        if(y+1 < 10 && vila1[x][y+1] == vila1[4][4]){ vila1[4][4]='H'; }
        if(y-1 >= 0 && vila1[x][y-1] == vila1[4][4]){ vila1[4][4]='H'; }


        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                printf("%c ", vila1[i][j]);
            }
            printf("\n");
		}
        
        
    }
	
    
	return 0;
}
