#include<iostream>
#include<Windows.h> // para SetConsoleOutputCP(1252)
#include<iomanip> // para setw(9)
using namespace std;
	//declarar estructura
	struct Producto{
		string codigoProducto;
		char nombreProducto[15];
		int cantidadExistente;
		float precioUnitario;
	}productos[3];
	
int main(){
	int opcion,casilla;
	string codigoBuscado;
	float sumatoria=0;
	float precioTotal;
	bool validar=false;
	do{
	bool encontrado=false;
	system("cls");
	cout<<"\t\tMENU PRINCIPAL"<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"* Ingresar Productos................1"<<endl;
	cout<<"* Mostrar Productos.................2"<<endl;
	cout<<"* Buscar Productos..................3"<<endl;
	cout<<"* Modificar Productos...............4"<<endl;
	cout<<"* Eliminar productos................5"<<endl;
	cout<<"* Salir.............................6"<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"Seleccione opcion: ";
	cin>>opcion;

		switch(opcion){
		//INGRESAR DATOS
		case 1:
		system("cls"); 
		cout<<"----------INGRESAR DATOS----------"<<endl;
			for(int i=0; i<=2;i++){
				system("cls");
				
				cout<<"\tDATOS DEL PRODUCTO NO."<<i+1<<"\t"<<endl;
				cout<<"------------------------------------"<<endl;
				cout<<"Ingresar codigo: ";
				cin>>productos[i].codigoProducto;
				cout<<"Ingresar Nombre: ";
				cin.ignore();
				cin.getline(productos[i].nombreProducto,50);
				do{
					cout<<"Ingresar cantidad: ";
					cin>>productos[i].cantidadExistente;
				}while(productos[i].cantidadExistente<0);
				
				do{
					cout<<"Ingresar precio: ";
					cin>>productos[i].precioUnitario;
				}while(productos[i].precioUnitario<0);
				cout<<"\nProducto guardado exitosamente..."<<endl;
				cout<<"------------------------------------"<<endl;
				system("pause");
				validar=true;
			}	
		break;
		
		//MOSTRAR DATOS
		case 2:
			system("cls");
			if(!validar){
				cout<<"\nERROR, debe ingresar datos"<<endl;
			}else{	
			cout<<"\t\t\tMOSTRANDO DATOS\t\t\t"<<endl;
			cout<<"------------------------------------------------------------------"<<endl;
			cout<<"CODIGO   NOMBRE DEL PRODUCTO      CANTIDAD    PRECIOU    TOTAL"<<endl;
			cout<<"------------------------------------------------------------------"<<endl;
			sumatoria=0;
			for(int i=0;i<=2;i++){
				precioTotal=productos[i].cantidadExistente*productos[i].precioUnitario;
				sumatoria=sumatoria+precioTotal;
				cout<<setw(9)<<left<<productos[i].codigoProducto<<' '
				<<setw(18)<<left<<productos[i].nombreProducto<<' '
				<<setw(9)<<right<<productos[i].cantidadExistente<<' '
				<<setw(9)<<right<<"Q"<<productos[i].precioUnitario<<' '
				<<setw(9)<<right<<"Q"<<precioTotal<<endl;
				}cout<<endl;
				cout<<setw(59)<<right<<"Gran total: Q"<<sumatoria<<endl;
				cout<<"------------------------------------------------------------------"<<endl;
			}		
			system("pause");
		break;
			
		//BUSCAR DATOS
		case 3:
			system("cls");
			if(!validar){
				cout<<"ERROR. debe ingresar datos..."<<endl;
			}else{
				cout<<"\t\tDATOS REGISTRADOS"<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				cout<<"CODIGO  NOMBRE DEL PRODUCTO     CANTIDAD  PRECIOU    TOTAL "<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				sumatoria=0;
				for(int i=0;i<=2;i++){
					precioTotal=productos[i].cantidadExistente*productos[i].precioUnitario;
					sumatoria=sumatoria+precioTotal;
					cout<<setw(8)<<left<<productos[i].codigoProducto<<' '
					<<setw(20)<<left<<productos[i].nombreProducto	
					<<setw(8)<<right<<productos[i].cantidadExistente<<' '
					<<setw(8)<<right<<"Q"<<productos[i].precioUnitario<<' '
					<<setw(8)<<right<<"Q"<<precioTotal<<endl;
				}
				cout<<setw(55)<<right<<"Gran Total Q: "<<sumatoria;
				cout<<"\n----------------------------------------------------------"<<endl;
				cout<<endl<<endl;
				cout<<"\t\tBUSCAR REGISTRO"<<endl;
				
				cout<<"Ingresar codigo a buscar: ";
				cin>>codigoBuscado;
				for(int i=0;i<=2;i++){
					if(codigoBuscado==productos[i].codigoProducto){
					encontrado=true;
					casilla=i;
					}
				}	
					if(encontrado==true){
							system("cls");
							
							cout<<"\t\tPRODUCTO BUSCADO"<<endl;
							cout<<"--------------------------------------------------------------"<<endl;
							cout<<"CODIGO   NOMBRE DEL PRODUCTO     CANTIDAD   PRECIOU     TOTAL"<<endl;
							cout<<"--------------------------------------------------------------"<<endl;
							cout<<setw(9)<<left<<productos[casilla].codigoProducto<<' '
							<<setw(18)<<left<<productos[casilla].nombreProducto
							<<setw(9)<<right<<productos[casilla].cantidadExistente<<' '
							<<setw(9)<<right<<"Q"<<productos[casilla].precioUnitario<<' '
							<<setw(9)<<right<<"Q"<<productos[casilla].precioUnitario*productos[casilla].cantidadExistente<<endl;
							cout<<"\n--------------------------------------------------------------"<<endl;
				}else{
					system("cls");
					cout<<"\nLO SIENTO, DATO NO ENCONTRADO..."<<endl;
					cout<<"-------------------------------------"<<endl;
				}
			}
			cout<<endl;
			system("pause");
		break;
			
		//MODIFICAR DATOS	
		case 4:
			system("cls");
			if(!validar){
				cout<<"ERROR, debe ingresar datos..."<<endl;
			}else{
				
				cout<<"\t\tDATOS REGISTRADOS"<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				cout<<"CODIGO  NOMBRE DEL PRODUCTO     CANTIDAD  PRECIOU    TOTAL "<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				sumatoria=0;
				for(int i=0;i<=2;i++){
					precioTotal=productos[i].cantidadExistente*productos[i].precioUnitario;
					sumatoria=sumatoria+precioTotal;
					cout<<setw(8)<<left<<productos[i].codigoProducto<<' '
					<<setw(20)<<left<<productos[i].nombreProducto	
					<<setw(8)<<right<<productos[i].cantidadExistente<<' '
					<<setw(8)<<right<<"Q"<<productos[i].precioUnitario<<' '
					<<setw(8)<<right<<"Q"<<precioTotal<<endl;
				}
				cout<<setw(55)<<right<<"Gran Total Q: "<<sumatoria;
				cout<<endl;
				cout<<"----------------------------------------------------------"<<endl<<endl;
				cout<<"\t\tMODIFICAR REGISTRO"<<endl;
				cout<<"Ingresar codigo a modificar: ";
				cin>>codigoBuscado;
				for(int i=0;i<=2;i++){
					if(codigoBuscado==productos[i].codigoProducto){
						encontrado=true;
						casilla=i;
					}
				}	
					system("cls");
					if(encontrado==true){
						cout<<"----------INGRESAR NUEVOS DATOS----------"<<endl;
						cout<<"Nuevo nombre: ";
						cin.ignore();
						cin.getline(productos[casilla].nombreProducto,50);
						
						do{
							cout<<"Nueva cantidad: ";
							cin>>productos[casilla].cantidadExistente;
						}while(productos[casilla].cantidadExistente<0 );
						
						do{
							cout<<"Nuevo precio: ";
							cin>>productos[casilla].precioUnitario;
						}while(productos[casilla].precioUnitario<0);
	 					
				}else{
					cout<<"\nLO SIENTO, DATO NO ENCONTRADO..."<<endl;
					cout<<"-----------------------------------"<<endl;
				}
						
		}
		system("pause");
		break;
			
		//ELIMINAR DATOS		
		case 5:
			system("cls");
			if(!validar){
				cout<<"ERROR, no se ha ingresado ningun dato..."<<endl;
			}else{
				cout<<"\t\tDATOS REGISTRADOS"<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				cout<<"CODIGO  NOMBRE DEL PRODUCTO     CANTIDAD  PRECIOU    TOTAL "<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				sumatoria=0;
				for(int i=0;i<=2;i++){
					precioTotal=productos[i].cantidadExistente*productos[i].precioUnitario;
					sumatoria=sumatoria+precioTotal;
					cout<<setw(8)<<left<<productos[i].codigoProducto<<' '
					<<setw(20)<<left<<productos[i].nombreProducto	
					<<setw(8)<<right<<productos[i].cantidadExistente<<' '
					<<setw(8)<<right<<"Q"<<productos[i].precioUnitario<<' '
					<<setw(8)<<right<<"Q"<<precioTotal<<endl;
				}
				cout<<setw(55)<<right<<"Gran Total Q: "<<sumatoria;
				cout<<endl;
				cout<<"----------------------------------------------------------"<<endl;
				cout<<endl<<endl;
				cout<<"\t\tELIMINAR REGISTRO"<<endl;
				cout<<"Ingresar codigo a eliminar: ";
				cin>>codigoBuscado;
				
				for(int i=0; i<=0;i++){
					if(codigoBuscado==productos[i].codigoProducto){
						encontrado=true;
						casilla=i;
					}
				}
				string respuesta;
				if(encontrado==true){
					cout<<"Desea realmente eliminar el producto [S/N] ";
					cin>>respuesta;
					if(respuesta=="S"){
						cout<<"\nEliminando datos..."<<endl;
						productos[casilla].codigoProducto="0";
						cin.getline(productos[casilla].nombreProducto,30);
						cout<<endl; 
						fflush(stdin); 
						productos[casilla].cantidadExistente=0;
						productos[casilla].precioUnitario=0;
						precioTotal=productos[casilla].cantidadExistente*productos[casilla].precioUnitario;
					}else{
						cout<<"Registro no eliminado..."<<endl;
					}
				
					
				}else{
					cout<<"\nDATO NO ENCONTRADO..."<<endl;
					cout<<"----------------------------------------------------------"<<endl;
				}						
			}			
			system("pause");
		break;
		
		//SALIR
		case 6:
			cout<<"\nGRACIAS POR USAR EL PROGRAMA..."<<endl;
			exit(0);
			system("pause");
		break;
		
		
	}
		
	}while(opcion!=6);
	
	
	
	
	
	
	
	
	
	return 0;
}
