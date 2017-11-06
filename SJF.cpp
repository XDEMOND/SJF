//@XDEMOND
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#define numProcesos 10
#define N 5
#define LinpPag 100

struct MMT
{
	int numMarco,locIni, estadoTMM;
   MMT *sig;
}*iM=NULL, *fM=NULL, *nuevoM=NULL, *auxM=NULL;

struct PCB
{
	int idProceso;
   int nPag;
   int tLlegada;
   int ciclos;
   int memoria;
   char cpuES[10];
   int archivos;
   int nDisp;
   char tipo[10];
   int estado;
   int trp;
   PCB *sig;
} *piPCB=NULL, *pfPCB=NULL, *paPCB=NULL,*pnPCB=NULL,*actual2=NULL,*siguiente2=NULL;

struct JT
{
	int tarea,seleccion;
   JT *sig;
}*iJ=NULL, *fJ=NULL, *nuevoJ=NULL, *auxJ=NULL;

struct PMT
{
	int numPagina,estado;
   PMT *sig;
}*iP[N], *fP[N], *nuevoP[N], *auxP[N];

void crearMMT(int valor1);
void imprimeMMT();
void cambiarEstadoA2();
void ordenarTLlegada();

void ordenarPCB()
{
	int proceso,npag,tllegada,ciclos,memoria,archivos,ndisp,estado,trp;
   char cpues[10],tipo[10];
	struct PCB *actual,*siguiente;
	actual=piPCB;
   paPCB=actual;
   while(actual->sig!=NULL)
   {
   	siguiente=actual->sig;
   	while(siguiente!=NULL)
      {
      	if(actual->ciclos>siguiente->ciclos)
         {
         	proceso=siguiente->idProceso;
            npag=siguiente->nPag;
            tllegada=siguiente->tLlegada;
            ciclos= siguiente->ciclos;
            memoria=siguiente->memoria;
            archivos=siguiente->archivos;
            ndisp=siguiente->nDisp;
            estado=siguiente->estado;
            trp=siguiente->trp;
            strcpy(cpues,siguiente->cpuES);
            strcpy(tipo,siguiente->tipo);

            siguiente->idProceso	=actual->idProceso;
            siguiente->nPag		=actual->nPag;
            siguiente->tLlegada	=actual->tLlegada;
            siguiente->ciclos		=actual->ciclos;
            siguiente->memoria	=actual->memoria;
            siguiente->archivos	=actual->archivos;
            siguiente->nDisp		=actual->nDisp;
            siguiente->estado		=actual->estado;
            strcpy(siguiente->tipo,actual->tipo);
            strcpy(siguiente->cpuES,actual->cpuES);

            actual->idProceso=proceso;
            actual->nPag=npag;
            actual->tLlegada=tllegada;
            actual->ciclos=ciclos;
            actual->memoria=memoria;
            actual->archivos=archivos;
            actual->nDisp=ndisp;
            actual->estado=estado;
            actual->trp=trp;
            strcpy(actual->tipo,tipo);
            strcpy(actual->cpuES,cpues);
         }siguiente=siguiente->sig;
      }actual=actual->sig;
   }
   ordenarTLlegada();
}

void ordenarTLlegada()
{

	int proceso,npag,tllegada,ciclos,memoria,archivos,ndisp,estado,trp;
   char cpues[10],tipo[10];
   actual2=piPCB;
   while(actual2->sig!=NULL)
   {
   	siguiente2=actual2->sig;
      while(siguiente2!=NULL)
      {
      	//if((actual2->ciclos)==(siguiente2->ciclos))
         //{
         	if((actual2->ciclos)==(siguiente2->ciclos)&&(actual2->tLlegada>siguiente2->tLlegada))
            {
            proceso=siguiente2->idProceso;
            npag=siguiente2->nPag;
            tllegada=siguiente2->tLlegada;
            ciclos= siguiente2->ciclos;
            memoria=siguiente2->memoria;
            archivos=siguiente2->archivos;
            ndisp=siguiente2->nDisp;
            estado=siguiente2->estado;
            trp=siguiente2->trp;
            strcpy(cpues,siguiente2->cpuES);
            strcpy(tipo,siguiente2->tipo);

            siguiente2->idProceso	=actual2->idProceso;
            siguiente2->nPag			=actual2->nPag;
            siguiente2->tLlegada		=actual2->tLlegada;
            siguiente2->ciclos		=actual2->ciclos;
            siguiente2->memoria		=actual2->memoria;
            siguiente2->archivos		=actual2->archivos;
            siguiente2->nDisp			=actual2->nDisp;
            siguiente2->estado		=actual2->estado;
            strcpy(siguiente2->tipo,actual2->tipo);
            strcpy(siguiente2->cpuES,actual2->cpuES);

            actual2->idProceso=proceso;
            actual2->nPag=npag;
            actual2->tLlegada=tllegada;
            actual2->ciclos=ciclos;
            actual2->memoria=memoria;
            actual2->archivos=archivos;
            actual2->nDisp=ndisp;
            actual2->estado=estado;
            actual2->trp=trp;
            strcpy(actual2->tipo,tipo);
            strcpy(actual2->cpuES,cpues);
            } siguiente2=siguiente2->sig;
         } actual2=actual2->sig;
      //}
   }
   cout<<"Tabla ordenada";
   system("pause");
}

void cambiarEstadoA2()
{
  	paPCB=piPCB;
   while(paPCB!=NULL)
   {
   	paPCB->estado=2;
      paPCB=paPCB->sig;
   }
}

void crearJT()
{
	int i=1;
   do
   {
   	if(iJ==NULL)
      {
      	iJ = (JT *)malloc(sizeof(JT));
         iJ->tarea = i;
         iJ->sig = NULL;
         fJ = iJ;
      }
      else
      {
      	nuevoJ = (JT *)malloc(sizeof(JT));
         nuevoJ->tarea = i;
         fJ->sig = nuevoJ;
         fJ = nuevoJ;
         fJ->sig = NULL;
      }
      i++;
   }while(i<=N);
}

void crearPCB()
{
		int i =1;
      int x=0;
      int cont=1;
      int cont2=0;
      int marcos=0;
      auxJ=iJ;
	  do
   	{
   		auxP[i] = iP[i];
      	while(auxP[i]!=NULL)
      	{
      		if(auxP[i]->estado==1)
            {
            	if(piPCB==NULL)
               {
              		paPCB = (PCB *)malloc(sizeof(PCB));
               	paPCB->idProceso=cont++;
               	paPCB->tLlegada = cont2++;
               	paPCB->ciclos = 1+rand()%(10);
               	paPCB->estado = 1;
               	paPCB->memoria =rand()%(101-1);
                  x=rand()%(501-1);
                  if((x%2)==0)
                  {
                  	strcpy(paPCB->cpuES,"CPU");
                     paPCB->nDisp =0;
                  }
                  else
                  {
                  	strcpy(paPCB->cpuES,"ES");
                     paPCB->nDisp =rand()%(7-1);
                  }
                  paPCB->archivos =rand()%(11-1);
                  if((x%2)==0)
                  	strcpy(paPCB->tipo,"SISTEMA");
                  else
                  	strcpy(paPCB->tipo,"USUARIO");
                     marcos++;

                  paPCB->sig = NULL;
                  piPCB = paPCB;
                  pfPCB=piPCB;
               }
            	else
            	{
            		paPCB = (PCB *)malloc(sizeof(PCB));
               	paPCB->idProceso=cont++;
               	paPCB->tLlegada = cont2++;
               	paPCB->ciclos = 1+rand()%(10);
               	paPCB->estado = 1;
               	paPCB->memoria =rand()%(101-1);
                  x=rand()%(501-1);
                  if((x%2)==0)
                  {
                  	strcpy(paPCB->cpuES,"CPU");
                     paPCB->nDisp =0;
                  }
                  else
                  {
                  	strcpy(paPCB->cpuES,"ES");
                     paPCB->nDisp =rand()%(7-1);
                  }
                  paPCB->archivos = rand()%(11-1) ;
                  if((x%2)==0)
                  	strcpy(paPCB->tipo,"SISTEMA");
                  else
                  	strcpy(paPCB->tipo,"USUARIO");

                     paPCB->sig = NULL;
                     pfPCB->sig=paPCB;
                     pfPCB=paPCB;
                     marcos++;
            	}
         	}
            auxP[i] = auxP[i]->sig;


      	}
         i++;
      //getch();
   }while(i<=5);

crearMMT(marcos);

}

void imprimeMMT()
{
   nuevoM = iM;

	cout<<" \t\t\t\t*****Tabla de Mapa de Memoria*****"<<endl;
   cout<<"\nNum.Marco\tLoc Ini\t\tEstado\n";
   while(nuevoM!=NULL)
   {
   	cout<<nuevoM->numMarco<<"\t\t"<<nuevoM->locIni<<"\t\t"<<nuevoM->estadoTMM<<endl;
      nuevoM = nuevoM->sig;
   }
}

void crearMMT(int valor1)
{
	int Marcos=valor1;
	int i=0;
   do
   {
   	if(iM==NULL)
      {
      	iM = (MMT *)malloc(sizeof(MMT));
         iM->numMarco = i;
         iM->locIni = (i+100);
         iM->estadoTMM = 0;

         iM->sig=NULL;
         fM = iM;
      }
      else
      {
      	nuevoM = (MMT *)malloc(sizeof(MMT));
         nuevoM->numMarco = i;
         nuevoM->locIni = (i+100);
         nuevoM->estadoTMM = 0;
         fM->sig = nuevoM;
         fM = nuevoM;
      }
      i++;
   }while(i<Marcos);

   imprimeMMT();
}

void crearPMT()
{
	int cont;
	int i=1;
   int j,x;
   auxJ = iJ;
   do
   {
   	cont=0;
   	for(j=0;j<5;j++)
      {
      	if(iP[i]==NULL)
         {
         	iP[i]=(PMT *)malloc(sizeof(PMT));
            iP[i]->numPagina = j;
            iP[i]->estado = rand()%2;
            if(iP[i]->estado==1)
            	cont++;
            iP[i]->sig = NULL;
            fP[i] = iP[i];
         }
         else
         {
         	nuevoP[i] = (PMT *)malloc(sizeof(PMT));
            nuevoP[i]->numPagina = j;
            nuevoP[i]->estado = rand()%2;
            if(nuevoP[i]->estado==1)
            	cont++;
            nuevoP[i]->sig = NULL;
            fP[i]->sig = nuevoP[i];
            fP[i] = nuevoP[i];
         }
      }
      i++;
      auxJ->seleccion=cont;
      auxJ = auxJ->sig;
   }while(i<=N);
}


void imprimePMT()
{
	int i=1, j;
   cout<<"\n  \t\t\t\t*****Tabla PMT*****"<<endl;
   do
   {
   	auxP[i] = iP[i];
   	cout<<"\nTabla J"<<i<<endl;
      cout<<"Pagina\tEstado\n";
      while(auxP[i]!=NULL)
      {
      	cout<<"P"<<auxP[i]->numPagina<<"\t"<<auxP[i]->estado<<endl;
         auxP[i] = auxP[i]->sig;
      }
      i++;
      //getch();
   }while(i<=5);
}

void imprimeJT()
{
   auxJ = iJ;
	cout<<"\n \t\t\t\t*****Tabla de Tareas*****"<<endl;
   cout<<"\nTarea\n";
   while(auxJ!=NULL)
   {
   	cout<<"J"<<auxJ->tarea<<"\tSeleccion: "<<auxJ->seleccion<<endl;
      auxJ = auxJ->sig;
   }
}

void imprimePCB()
{
	paPCB=piPCB;
   cout<<"\n \t\t\t\t*****Tabla PCB*****"<<endl;
   cout<<"\nProceso\tT.lleg\tCiclos\tEstado\tMemoria\tCPU/ES\tNum_Dispvt Archivos\tTipo"<<endl;
   while(paPCB!=NULL)
   {
      cout<<paPCB->idProceso<<"\t"<<paPCB->tLlegada<<"\t"<<paPCB->ciclos<<"\t"<<paPCB->estado<<"\t"<<paPCB->memoria<<"\t"<<paPCB->cpuES<<"\t";
      cout<<paPCB->nDisp<<"\t\t"<<paPCB->archivos<<"\t"<<paPCB->tipo<<endl;
      paPCB=paPCB->sig;
   }
   system("pause");
}

void FCFS()
{
	auxM=iM;
    pnPCB=piPCB;
    float tps=0;
    imprimePCB();
    while((pnPCB!=NULL)&&(auxM!=NULL))
    {
        pnPCB->estado=3;
        auxM->estadoTMM=1;
        imprimeMMT();
        while(pnPCB->ciclos>0)
        {
            pnPCB->ciclos--;
            imprimePCB();
            tps=tps+1;
        }
        pnPCB->trp=tps;
        pnPCB->estado=5;
        auxM->estadoTMM=0;
        pnPCB=pnPCB->sig;
        auxM=auxM->sig;
    }
    pnPCB=piPCB;

    cout<<"\t\t\tTRP :";


    int no=0;
    tps=0;

    while(pnPCB!=NULL)
    {
        cout<<"P"<<pnPCB->idProceso<<": "<<pnPCB->trp<<"ms"<<endl;
        tps=tps+pnPCB->trp;
        pnPCB=pnPCB->sig;
        no++;
    }
    cout<<"\n\nTiempo Promedio del Sistema: "<<tps/no<<"ms"<<endl;
}

void main()
{
	crearJT();
   crearPMT();
   imprimePMT();
   imprimeJT();
	crearPCB();
   imprimePCB();
   ordenarPCB();
   imprimePCB();
   cambiarEstadoA2();
   FCFS();
   system("pause");
}