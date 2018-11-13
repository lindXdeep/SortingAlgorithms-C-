#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
using namespace std;

  class Initialization
  {
 protected:
   	int *LoadArray;     		//Главный массив
   	int size;      			//размер массива

    int str;	           		//Длина строки введенной в качеестве параметра
    int countNunb;       		//Счетчик для цифр
    int countChar;       		//Счетчик для символов
    char *SourceArray;  		//Указатель на исходный масив
    char *NumbCollect;  		//Указатель на массив хранящщий найденные числа
    char *CharCollect;   		//Указатель на массив хранящщий найденные символы
    int *IntArrResults; 		//Промежуточный Integer Массив
    int IntResults;    	 	//П для результирующщегго числа
 public:
    Initialization(int *Ar, const char *s);    //инициализация массива
    Initialization(int *Ar, int s);
    ~Initialization();

    void initialize(int *Ar, int size);
    int ToInt(int *Arr, int N);
    bool Symbol(char smbl);
    void SystemInfo();
     };

  class Sort:public Initialization
  {
    int *Array;
    clock_t t;
    int c;    //Итерации
    int e;    //сравнения
    int s;    //перестановки

    bool WhatArr = false;
    int *MistakeArray;
    int CountMistake;
 public:
    Sort(int *Ar, const char *s):Initialization(Ar, s){cout << "Constr Sort\n"; };    //инициализация массива
    Sort(int *Ar, int s):Initialization(Ar, s){cout << "Constr Sort\n";};
    ~Sort();

    void swap(int &left, int &right);
    void Mixed();
    void show();    //Показать массив
    void CheckArray();
    void CreateNewData();

    void SelectionSort();
    void BubbleSort();
    void SumBubbleSort();
    void ShakerSort();
    void InsertSort();
    void ShellSort();
    void downHeap(int k, int s);
    void HeapSort();
    void QuickSort();
    void qsort(int left, int right);
    void QuickSortMod();
    void Counting();
  };

  int Initialization::ToInt(int *Arr, int N)	//Массив в чиисло
 {
	  int *integer = new int(0);
	  int i = N, j = 1;
		while (i-- >=  0)
		{
			if (i < 0) return  *integer;
			(*integer )+=(Arr[i] * j);
			j *= 10;
		}
		delete integer;
	return 0;
	}

  bool Initialization::Symbol(char Smbl)			//Идентификатор символов
  {
	if (Smbl >= '0' && Smbl <= '9')
		return true;
  return false;
  }

  Initialization::Initialization(int *Ar, const char *s)
  {
   cout << "\nConstr Initialize\n";

    str = strlen(s)+1;									//размер массива и + 1 для последнего элемента

	SourceArray = new char(str);				//Исходный массив	 для неотсортрованного мусора в char формате
	NumbCollect = new char(str);				//Массив для отсортированных числел в char формате
	CharCollect = new char(str);				//Массив для отсортированных букв в char формате

	countNunb = 0;											//Счетчик количества цифр
  countChar = 0;											//Счетчик количества букв

	int i = 0;
	while(str != i) 					//Сортировка  символов на буквы и числа в 2 массива в char формате
	{
		SourceArray[i] = s[i];

		if( Symbol(s[i]) )
		{
		  NumbCollect[countNunb] = s[i];
		  countNunb++;
		}
		else
		{
		  CharCollect[countChar] = s[i];
		  countChar++;
		}
	i++;
	}
				//Завершаем массивы символов элементом конца строки
	SourceArray[str] = '\0';
	NumbCollect[countNunb] = '\0';
	CharCollect[countChar] = '\0';

	if(str > 25 || countChar > 20 || countNunb > 5)
	{
		cout << "\n ! ! ! ERROR ! ! !" ;
		SystemInfo();
	}

  IntArrResults = new int[countNunb];		//содаем результирующий массив int формата размера массива char

	int IntCount = 0;
	 while( IntCount != countNunb ) 			  //Конвектор из char Массива  в  int масив
	 {
		  switch(NumbCollect[IntCount])
		 {
		   case '0': IntArrResults[IntCount] = 0; break;
		   case '1': IntArrResults[IntCount] = 1; break;
		   case '2': IntArrResults[IntCount] = 2; break;
		   case '3': IntArrResults[IntCount] = 3; break;
		   case '4': IntArrResults[IntCount] = 4; break;
		   case '5': IntArrResults[IntCount] = 5; break;
		   case '6': IntArrResults[IntCount] = 6; break;
		   case '7': IntArrResults[IntCount] = 7; break;
		   case '8': IntArrResults[IntCount] = 8; break;
		   case '9': IntArrResults[IntCount] = 9; break;
		 }
		IntCount++;
	}
  IntResults = ToInt(IntArrResults, IntCount);

    if(IntResults <= 1 )
    {
      cout << "\n ! ! ! ERROR ! ! !" ;
      SystemInfo();
    }

	size = IntResults;
	initialize(Ar, size);
  }

  Initialization::Initialization(int *Ar, int s)
  {
   size = s;
   initialize(Ar, size);
  }

  void Initialization::initialize(int *Ar, int size)
  {
   LoadArray = new int[size];
    for (int i = 0; i < size ; i++ )
      LoadArray[i] = Ar[i];
 }

  void Initialization::SystemInfo()
  {
	cout << " -> Press \"i\" to show Info or \"any key\" to Exit" <<endl;

		if(char ch = (getchar () != 'i') || ch == char('13'))
			exit(1);
		else
		{
		cout << "\t----System informations----\n";
			cout << "\nSource data ["  << str-1 << "] " ;
				for (int i = 0; i < str-1; ++i)
					cout << SourceArray[i];

			cout << "\nCHAR's data [" <<  countChar << "] ";
				for (int i = 0; i < countChar; ++i)
					cout << CharCollect[i];

			cout << "\nNUMB's data [" << countNunb << "] ";
				for (int i  = 0; i < countNunb; i++)
					cout << NumbCollect[i];

			if(str > 25 )
			{
				cout << "\nYou inpput \"" << str << "\" symmbol.  Max 25" <<endl;
				exit(1);
			}
			else if(countChar > 20)
			{
				cout << "\nInput data contains \"" << countChar << "\" char simbols.  Max 20" <<endl;
				exit(1);
			}
			else if(countNunb > 5 || countNunb <= 1 )
			{
				if (countNunb > 5)
				{
					cout << "\nInput data contains \"" << countNunb << "\" numbers.  Max Numb (99 999)" <<endl;	exit(1);
				}
				else if(countNunb <= 1)
				{
					cout << "\nYou Size \"" << IntResults << "\" Size Array dont be less 2 elements\""; exit(1);
				}
			}
		}
	}

  Initialization::~Initialization()
  {
   cout << "\ndistr init\n";
    delete[] SourceArray;
    delete[] CharCollect;
    delete[] NumbCollect;
    delete[] IntArrResults;
    delete[] LoadArray;
  }

  Sort::~Sort()
  {
	 delete[] Array;
	cout << "\ndistr Sort"<<endl;
  }

  void Sort::CreateNewData()
  {
    if(Array) delete[]Array;
      Array = new int[size];
        for(int i  = 0; i < size; i++)
          Array[i] = LoadArray[i];

    WhatArr = true;
    t = clock();
    c = 0;
    e = 0;
    s = 0;

	 }

  void Sort::CheckArray()   //Проверка ошибок
  {
    CountMistake = 0;
    for (int i = 0; i<size-1; i++)     //Количество итераций
    {
      if(Array[i] > Array[i+1] )
        CountMistake++;
    }

    if (!CountMistake) return;

    cout << "Mistakes: " << CountMistake << " Elements: ";

    MistakeArray = new int[CountMistake];
    int j = 0;
      for (int i = 0; i<size-1; i++)     //Количество итераций
      {
        if(Array[i] > Array[i+1] )
        {
          MistakeArray[j] = Array[i];
          cout << MistakeArray[j] << "|" ;
         j++;
        }
      }
     cout << endl << endl;
   delete[] MistakeArray;

  }

  void Sort::show()
  {
   t = clock() - t;

   int count = 0;
   cout << "Begin ";

   for(int i = 0; i < size; i++ )
   {
    if(WhatArr)
      cout << "[" << Array[i] <<"]";
    else
      cout << "[" << LoadArray[i] <<"]";

    count++;

      if (count==10)
      {
        cout << endl;
        count = 0;
      }
    }
  cout << "End\n" <<endl;

  if(c)
  {
    cout << "Iter: " << c << endl;
    cout << "Eqil: " << e << endl;
    cout << "Swap: " << s << endl;
    cout << "Time: " << ((float)t) / CLOCKS_PER_SEC << endl;
  }

   if(WhatArr) CheckArray();

  WhatArr = false;
  }

  void Sort::swap(int &left, int &right)  //Функция меняет местами два эленмента
  {
    int *tmp = new int;
    (*tmp) = left;
    left = right;
    right = (*tmp);
  delete tmp;
  }

  void Sort::Mixed()  //Функция перемешивает массив
  {
   srand(time(NULL));  // что бы был рандом иначе будут одни и теже числа.

   for(int i = 0; i < size; i++)
   {
     int rnd = rand() % size;
     swap(LoadArray[i], LoadArray[rnd]);
   }
  }

  void Sort::SelectionSort() //Сортировка прямым выбором
  {
  CreateNewData();

    for (int i = 0; i<size; i++)     //Количество итераций
    { c++;
      for (int j = i+1; j<size; j++)   //Диапозон просматриваемых значений сокращается с каждой итерацие
      { e++;
        if(Array[i] > Array[j])    //Проход для нахождения самого маленького
        {s++;
           swap(Array[i], Array[j]);   // меняем местами если сравниваемое число меньше текущего минимального
        }
      }
    }
  }

  void Sort::BubbleSort()        //Обычная оптимизированная сортировка пузырьком
  {
  CreateNewData();

    for (int i=1; i<=size; i++)
    { c++;
      for (int j=0; j<size-i; j++)
      { e++;
        if (Array[j] > Array[j+1])
        {  s++;
           swap(Array[j], Array[j+1]); s++;
        }
      }
    }
  }

  void Sort::SumBubbleSort()  //останавливающийся пузырьки
  {
  CreateNewData();

    bool stop = false;

    for (int i=0; i<size-1; i++)
    { c++;
    stop = false;

      for (int j=0; j<size-i; j++)
      { e++;
        if (Array[j] > Array[j+1])
        {
         swap(Array[j], Array[j+1]); s++;
         stop = true;   //Не останавливается пока есть перестановка
        }
      }
     if(!stop) break; // выход из цикла если не совершена перестановка
    }
  }

  void Sort::ShakerSort()
  {
  CreateNewData();

     int j, k;
     int lb = 0, rb = size-1;  // границы неотсортированной части массива

   do
    { c++;
     for(j = 1; j <= rb; j++ )
     { e++;
       if(Array[j-1]>Array[j])
       {
         swap(Array[j-1],Array[j]);  s++;
         k = j;
       }
     }
     rb = k - 1;

     for(j = rb; j > 0; j-- )
     { e++;
       if(Array[j-1]>Array[j])
       {
         swap(Array[j-1],Array[j]);  s++;
         k = j;
       }
     }
     lb = k + 1;

    }while(lb < rb);
  }

  void Sort::InsertSort()
  {
    CreateNewData();

    int x,b, i,j;
     for(i = 0; i < size; i++)
     { c++;
       x = Array[i];
       for(j = i-1; j>=0 && Array[j]>x ;j--)
       {
         Array[j+1]=Array[j];  s++;
       }
      Array[j+1]=x;
     }
  }

  void Sort::ShellSort()
  {
    CreateNewData();

  int i,  j,  d,  x;
      i = j = d = x = 0;

    d = size/2;   //делим масив на 2 части

     while(d>0)
    {c++;
      for(i=d; i<size; i++)
      { e++;
        x = Array[i];

        for(j=i-d; (j >= 0) && (Array[j] > x); j-=d)
        {
          Array[j+d] = Array[j]; s++;
        }
        Array[j+d] = x;
      }
     d = d/2;
    }
  }

  void Sort::downHeap(int k, int s) // Постройка пирамиды(самый большой элемент поднимается наверх)
  {
    int elem = Array[k];          // сохраняем наш текущий
    int child;                    // Сын (последний элемент от текущего элемента)

      while(k <= s/2)             //проверяем на наличие сыновей
      {c++;
        child=2*k;                //находим Сына Array[2*i+1]

        if( (child < s) && (Array[child] < Array[child+1])) //Если сын1 < сын2
          child++;               //Тогда выбираем второго(Array[2*i+2]), оно полюбому больше.

        if(elem >= Array[child]) // если сын меньше то все впорядке, выходим из цикла
          break;
      e++;
        swap(Array[k],Array[child]);  //если сын больше родителя то меняем местами
        k = child;    //и востанавливаем текущий элемент так мы их поменяли местами
      }
   }

  void Sort::HeapSort()
  {
    CreateNewData();

      for(int i = size/2-1; i >= 0; i--)//нахождение самого болшого элемента
      {
         downHeap(i, size-1);
      }

      for(int i = size-1; i > 0; i--)   //сортировка
      {
        swap(Array[0],Array[i]);  //Меняем местами первый и последний элементы

         downHeap(0, i-1); //если мы будем с каждой итерацие общее количество ументшать на 1
      }                     //тогда путем деления
   }

  void Sort::QuickSort()
  {
    CreateNewData();
    qsort(0, size-1);
  }

  void Sort::qsort(int left, int right)
  {
    int l=left, r=right;
    int p=Array[(left+right) / 2];

    do{ c++;
      while (Array[l]<p) l++;
      while (Array[r]>p) r--;
      if (l<=r)
      {
         swap(Array[l++], Array[r--]); s++;
      }

    }while (l<=r);

    if (r > left) qsort( left, r);
    if (l < right) qsort(l, right);
  }

  void Sort::QuickSortMod()
  {
    CreateNewData();

    int MAXSTACK = 2048;  //максимальный размер стека

     //Каждый запрос это всегда пара значений (lbstack rbstack) левая и правая граница промежутка
    int lbstack[MAXSTACK];   //левый массив запросов
    int rbstack[MAXSTACK];   //правый массив запросов
    int stackpos = 1;          // текущая позиция стека
    lbstack[1] = 0;
    rbstack[1] = size-1;

    int leftb, rightb, midArr; //границы сортируемого в цикле фрагмента и середина массива

    int l, r, p;   // указатели, участвующие в разделении и опорный элемент

    do
    {
       // Берем границы left и right из текущего массива из стека.
       leftb = lbstack[stackpos];
       rightb = rbstack[stackpos];
       stackpos--;
      do
      {
         // Шаг 1. Разделение по элементу pivot
        midArr = (leftb + rightb)>>1 ;     //Находим середину массива
        p = Array[midArr];
        l = leftb;              //поолулчаем  левую границу
        r = rightb;             //и правую

        do
        {
          while(Array[l++] < p);
          while(p < Array[r--]);

          if(l <= r) swap(Array[l++], Array[r--]);

        }while( l <= r );

      // Сейчас указатель l указывает на начало правого подмассива, а r - на конец левого

		  // Возможен случай, когда указатель l или r выходит за границу массива
      //Шаги 2, 3. Отправляем большую часть в стек  и двигаем leftb, rightb,

        if(l < midArr)
        {       // Если правая часть больше
          if(l < rightb)
          {     //  сортировать, (запрос в стек)
             stackpos++;
             lbstack[ stackpos ] = l;
             rbstack[ stackpos ] = rightb;
          }
          rightb = r; // следующая итерация разделения	(будет работать с левой частью)
        }
        else
        {     //Если левая часть больше
          if ( r > leftb )
          {
            stackpos++;
            lbstack[ stackpos ] = leftb;
            rbstack[ stackpos ] = r;
          }
          leftb = l;
        }
      }while(leftb < rightb);   //Цикл работает до тех пор пока получает значения правой границы масива
    }while(stackpos != 0);      //цикл работает пока индекс масисва не станет нуливым
  }

  void Sort::Counting()
  {
    CreateNewData();



  }



 int main()
{
  int N = 10 ;     		//тест на цифры
  char* M ={"fs1f0"};  	//тест на символы

  int Massiv[N];
  cout << "-----Sourse shit------:\n";
  for (int i = 0; i < N; i++ )
  {
     Massiv[i] = i;
  cout << Massiv[i] << "|";
  }

cout <<"\n\t\t- - - - - - - - ALGORITMS SORTING- - - - - - - - "<<endl;

  cout << "\n\n------initialization Array------";
  Sort ob(Massiv, M);   //инициализация массивом
  ob.show();

  cout << "\n-----Mixed Array-----" << endl;
  ob.Mixed();
  ob.show();

  cout << "\n------Selection Sort------" << endl;
  ob.SelectionSort();
  ob.show();

  cout << "\n------Buble Sort------" << endl;
  ob.BubbleSort();
  ob.show();

  cout << "\n------Sum Bubble Limit Bubble Sort------" << endl;
  ob.SumBubbleSort();
  ob.show();

  cout << "\n------Shaker Sort------" << endl;
  ob.ShakerSort();
  ob.show();

  cout << "\n------Insert Sort------" << endl;
  ob.InsertSort();
  ob.show();

  cout << "\n------Shell Sort------" << endl;
  ob.ShellSort();
  ob.show();

  cout << "\n------Heap Sort------" << endl;
  ob.HeapSort();
  ob.show();

  cout << "\n------Quick Sort------" << endl;
  ob.QuickSort();
  ob.show();

  cout << "\n------Quick Sort Modified------" << endl;
  ob.QuickSortMod();
  ob.show();

  cout << "\n------Counting Sort ------" << endl;
  ob.Counting();
  ob.show();




	ob. SystemInfo();
	return 0;
}



