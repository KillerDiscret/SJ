#include<iostream>
using namespace std;
int main()
{
	int i, j, n, min, k = 1, SumaTiempoDuracion = 0, DuracionTotal = 0, Suma = 0;
	int TDuracion[10], aux, TArrivo[10], TiempoEspera[10], Volver[10], OrdenProcesos[10] = { 1,2,3,4,5,6,7,8,9,10 };
	float EsperaMedia = 0, TAMedio = 0, SumaVuelta = 0, sumaTiempoEspera = 0;
	cout << "Ingrese el numero de procesos: "; cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "\nIngrese el tiempo de llegada del proceso " << i + 1 << " :";
		cin >> TArrivo[i];
		cout << "Ingrese el tiempo de duracion del proceso " << i + 1 << " :";
		cin >> TDuracion[i];
	}
	//-----------------------Ordenamiento por tiempo de llegada-------------------------
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (TArrivo[i] < TArrivo[j])
			{
				aux = OrdenProcesos[j];
				OrdenProcesos[j] = OrdenProcesos[i];
				OrdenProcesos[i] = aux;
				aux = TArrivo[j];
				TArrivo[j] = TArrivo[i];
				TArrivo[i] = aux;
				aux = TDuracion[j];
				TDuracion[j] = TDuracion[i];
				TDuracion[i] = aux;
			}
		}
	}
	//--------Ordenar por tiempo de duracion,tiempo de ejecucion y tiempo de llegada---------
	for (j = 0; j < n; j++)
	{
		SumaTiempoDuracion += TDuracion[j];
		min = TDuracion[k];
		for (i = k; i < n; i++)
		{
			if (SumaTiempoDuracion >= TArrivo[i] && TDuracion[i] < min) {
				aux = OrdenProcesos[k];
				OrdenProcesos[k] = OrdenProcesos[i];
				OrdenProcesos[i] = aux;
				aux = TArrivo[k];
				TArrivo[k] = TArrivo[i];
				TArrivo[i] = aux;
				aux = TDuracion[k];
				TDuracion[k] = TDuracion[i];
				TDuracion[i] = aux;
			}
		}
		k++;
	}

	TiempoEspera[0] = 0;
	for (i = 1; i < n; i++)
	{
		Suma += TDuracion[i - 1];
		TiempoEspera[i] = Suma - TArrivo[i];
		sumaTiempoEspera += TiempoEspera[i];
	}
	EsperaMedia = (sumaTiempoEspera / n);
	for (i = 0; i < n; i++)
	{
		DuracionTotal += TDuracion[i];
		Volver[i] = DuracionTotal - TArrivo[i];
		SumaVuelta += Volver[i];
	}
	cout << "\n\n";
	for (i = 0; i < n; i++)
	{
		cout << "\nProceso: " << OrdenProcesos[i] << "\tLlegada: " << TArrivo[i] << "\tDuracion: "
			<< TDuracion[i] << "\tEspera: " << TiempoEspera[i] << "\tTiempo de respuesta: " << Volver[i];
	}
	cout << "\n\nTiempo de espera promedio: " << EsperaMedia;
	cout << "\nTiempo de respuesta promedio: " << TAMedio;
	system("PAUSE");
	return 0;
}
