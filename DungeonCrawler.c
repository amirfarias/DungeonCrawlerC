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
    
    char vila[10][10] = {
        {'*', '*', '*', '*', '*', ' ', '*', '*', '*', '*'},
        {'*', ' ', ' ', ' ', '*', 'L', '*', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', 'H', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}  
    };
 
    #ifdef _WIN32
       system("cls");
    #else
        system("clear");
    #endif
    
	if(vida_bot < 1){ vida_bot = 1; }
	if(vida_botP < 1){ vida_botP = 1; }
	x = 7; 
	y = 6; 
	
 	vila[x][y] = '>';
}    