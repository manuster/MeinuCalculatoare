#include <stdio.h>
#include <string.h>
int nr = 0;
int r = 0;
struct calculator
{
	char procesor[50];
	char placa[50];
	int pret;
}calc[50],ca;
void afisare()
{
	int i;
	for (i = 0;i < nr;i++)
	{
		printf("%s %s %d\n", calc[i].procesor,calc[i].placa,calc[i].pret);
	}
}
void afisare_intel(char *pro)
{
	int i = 0;	
	while (i < nr)
	{
		if(strcmp(calc[i].placa, pro) == 0)
		{
			printf("%s %s %d\n", calc[i].procesor, calc[i].placa, calc[i].pret);
		}
		i++;
	}

}
void sortare()
{
	char *aux;
	int au;
	int i, k;
	do {
		k = 1;
		for(i=0;i<nr-1;i++)
			if (calc[i].pret > calc[i + 1].pret)
			{
				ca = calc[i];
				calc[i] = calc[i + 1];
				calc[i + 1] = ca;
				k = 0;
			}
	} while (!k);
	afisare();

}
void schimbare_pret(char *dat,char *pla)
{
	char proc[20];
	char plac[20];
	int pr;
	while(r<nr)
	{
		
			if (((strcmp(calc[r].procesor, dat) == 0)) & ((strcmp(calc[r].placa, pla) == 0)))
			{
				printf("Noul pret");
				scanf("%d", &pr);
				calc[r].pret = pr;
				printf("%s %s %d", calc[r].procesor, calc[r].placa, calc[r].pret);

			}
		
	}


}
int main()
{
	char* str;
	char pro[50],dat[50],pla[50];
	char fisier[] = "Calculatoare.txt";
	FILE* f = fopen(fisier, "rt");
	
	int opt;
	do {
		printf("\n1.Adauga calculator nou.\n");
		printf("2.Afiseaza toate calculatoarele.\n");
		printf("3.Afiseaza toate calculatoarele cu procesor intel:\n");
		printf("4.Sortare dupa pret a tutuor calculatoarelor:\n");
		printf("5.Schimba pretul unui calculator:\n");
		printf("Optiunea dorita:\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			while (!feof(f))
			{
				fscanf(f, "%s %s %d", calc[nr].procesor, calc [nr] .placa, &calc[nr].pret);
				nr++;
			}
			break;
		case 2:
			afisare();
			break;
		case 3:
			printf("Tipul procesorului:");
			scanf("%s", pro);
			afisare_intel(pro);
			break;
		case 4:
			sortare();
			break;
		case 5:
			printf("Procesoru:");
			scanf("%s", dat);
			printf("Placa:");
			scanf("%s", pla);
			schimbare_pret(dat,pla);
			break;

		}
	} while (opt != 0);
	return 0;
}