#include "Scena.hh"


Scena::Scena(){
  shared_ptr<Robot> robot1 (new Robot(Wektor2D(100,50)));
  shared_ptr<Robot> robot0 (new Robot(Wektor2D(50,50)));
  shared_ptr<Robot> robot2 (new Robot(Wektor2D(150,50)));
 
  shared_ptr<ObiektGraficzny> przeszkoda1(new Przeszkody(Wektor2D(50,150)));
  shared_ptr<ObiektGraficzny> przeszkoda2(new Przeszkody(Wektor2D(150,200)));
  shared_ptr<ObiektGraficzny> przeszkoda3(new Przeszkody(Wektor2D(200,60)));

 
   roboty.push_back(robot0);
   roboty.push_back(robot1);
   roboty.push_back(robot2);

    
   obiekty.push_back(przeszkoda1);
   obiekty.push_back(przeszkoda2);
   obiekty.push_back(przeszkoda3);
   
   aktRob=robot0; 
 
 }

inline void delay(unsigned long ms){
  usleep(ms*1000);
}

void Scena::wyswietlAktywnego(){
  cout<<aktRob->polozenie<<endl; 
 }

void Scena::wyswietlInne(){
  list<shared_ptr <Robot>>::iterator ite;
  int i=-1;
  for(ite = roboty.begin(); ite!=roboty.end(); ++ite)
    { ++i;
      if((*ite)!=aktRob)
	cout<<i<<". "<<(*ite)->polozenie<<endl;

    }
}

void Scena::Dodaj(){
  
  
  Wektor2D pol;
  int j;
  
 cout<<"Co chcesz dodac ?"<<endl
      <<"1. Robot"         <<endl
      <<"2. Przeszkoda"    <<endl;

  cin>>typ;

  do{
  j=0;
  cout<<"Gdzie utworzyc obiekt ?"<<endl;
  cin>>pol;

  if(!czynachodzi(pol,typ)){
    
    cout<<"Wpisz wspolrzedne nowego obiektu jeszcze raz !"<<endl;
    j=1;
  }

    
 }while(j==1);


  if(typ==1){
    
  roboty.push_back(static_pointer_cast<Robot>(Fabryka::Zbuduj(TO_Robot,pol)));

  
  }

  else if(typ==2){
    
    obiekty.push_back( Fabryka::Zbuduj(TO_Przeszkoda,pol));

}

  

  rysuj();
}


void Scena::zmienPr(double pr){
  aktRob->predkosc=pr;

}


ostream& operator <<(ostream &Strm,  Scena &Scena)
{
  
  
  for( list<shared_ptr <ObiektGraficzny>>::iterator it = Scena.obiekty.begin(); it!=Scena.obiekty.end(); ++it)
  Strm<<(**it)<<endl<<endl;
  
  return Strm;
}



void Scena::PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy)
{

  for( list<shared_ptr <Robot>>::iterator ite = roboty.begin(); ite!=roboty.end(); ++ite)
  StrmWy<<(**ite)<<endl<<endl;

    
  for( list<shared_ptr <ObiektGraficzny>>::iterator it = obiekty.begin(); it!=obiekty.end(); ++it)
    {

      StrmWy<<(**it)<<endl<<endl;


  }
    
}

void Scena:: zmianaRobota(int wybor)
{
  list<shared_ptr <Robot>>::iterator ite = roboty.begin();
  for(int i=0; i<wybor ;i++)
    ite++;

  aktRob=(*ite);
      
}



bool Scena::PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku )
{
    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy);


    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}


/*
void Scena::jedz(double &ile)
{   int i=0;
    double mod; 
    mod=(int(ile))%(int(aktRob->predkosc)); 
    
    
    if(ile<aktRob->predkosc) 
    {
        aktRob->jedz(ile);
        rysuj();
	if(czykraksa()){
	  aktRob->jedz((-ile));
         
	  
	}
	rysuj();
      
        }


     else  
    {
        while( i<ile)  
        {
            i=i+aktRob->predkosc;
            aktRob->jedz(aktRob->predkosc);
	     if(czykraksa()){
	      
	     aktRob->jedz(-aktRob->predkosc);
	    }
	    rysuj();

            if(i==ile-mod) 
            {
                i=i+((int)mod);
                aktRob->jedz(double(mod));
		if(czykraksa()){
		  
		  aktRob->jedz(-double(mod));
		}
		rysuj(); 

            }
             
	    delay(250);
	}
    }
    
    
}


*/





















void Scena::jedz(double &ile)
{   
    int i=0;
    double mod; 
    double pojedynczy=1;
    double droga=0;

 while((czykraksa()==false) && (droga<ile)){
        aktRob->jedz(pojedynczy);  
        droga++;
        aktRob->sciezka.Wierz_Glb.pojemnik.pop_back();
    }
      
  
          aktRob->jedz(-droga);
	  droga=droga-1;
	 
   mod=(int(droga))%(int(aktRob->predkosc)); 
    
    
    if(droga<aktRob->predkosc) 
    {
        aktRob->jedz(droga);
        rysuj();
      
        }

    
     else  
       {
        while( i<droga)  
        {
            i=i+aktRob->predkosc;
            aktRob->jedz(aktRob->predkosc);
	   
	    rysuj();

            if(i==droga-mod) 
            {
                i=i+((int)mod);
                aktRob->jedz(double(mod));
		rysuj(); 

            }
             
	    delay(250);
	}
    }
      
    
}


bool Scena::czykraksa()
{
  bool czybum=false;
  list<shared_ptr <ObiektGraficzny>>::iterator it;
  list<shared_ptr <Robot>>::iterator ite;
  double odleglosc;
  


  for(it = obiekty.begin(); it != obiekty.end(); ++it)
     {

  if( aktRob->polozenie[0] > ( (*it)->Wierz_Glb.pojemnik[0][0]-10) &&
      aktRob->polozenie[0] < ( (*it)->Wierz_Glb.pojemnik[1][0]+10) &&
      aktRob->polozenie[1] < ( (*it)->Wierz_Glb.pojemnik[0][1]+10) &&
      aktRob->polozenie[1] > ( (*it)->Wierz_Glb.pojemnik[2][1]-10)  ){
    
      cout<<"KRAKSA"<<endl;
    
    czybum=true;
  }
     }

  

  for(ite = roboty.begin(); ite != roboty.end(); ++ite)
     {
       
odleglosc= 
sqrt((aktRob->polozenie[0]-(*ite)->polozenie[0])*(aktRob->polozenie[0]-(*ite)->polozenie[0])  +
     (aktRob->polozenie[1]-(*ite)->polozenie[1])*(aktRob->polozenie[1]-(*ite)->polozenie[1]));
 
 if( odleglosc < 20 && odleglosc > 0 ){
   
     cout<<"KRAKSA"<<endl;
   
   czybum=true;
 }
     }

  return czybum;
}


void Scena::obrot(double &stp,Macierz2x2 &mac)
{
    double stop=stp/4;
    for(int i=0; i<4; i++)
    {
        mac.wypelnij(stop);
        aktRob->obrot(mac);
        
        rysuj();
        delay(250);
    }
}



int Scena::rysuj()
{
    if (!PrzykladZapisuWspolrzednychDoPliku("obiekt.dat"))
        return 1;
    Lacze.Rysuj();
    return 0;

}

void Scena::translacja(Wektor2D &tran)
{

  
  for( list<shared_ptr <Robot>>::iterator ite = roboty.begin(); ite!=roboty.end(); ++ite)
    ((*ite)->polozenie)+tran;

    
  for( list<shared_ptr <ObiektGraficzny>>::iterator it = obiekty.begin(); it!=obiekty.end(); ++it)
    {
      for(unsigned int i=0; i<(*it)->Wierz_Glb.pojemnik.size();i++)
	((*it)->Wierz_Glb.pojemnik[i])+tran;


    }
  
}

bool Scena::czynachodzi(Wektor2D polNowego,int typ){
  bool czybum=true;
  double odleglosc;
  list<shared_ptr <ObiektGraficzny>>::iterator it;
  list<shared_ptr <Robot>>::iterator ite;
  
  for(it = obiekty.begin(); it != obiekty.end(); ++it)
     {
       if(typ==2)
         if( polNowego[0] >= ( (*it)->Wierz_Glb.pojemnik[0][0]-25) &&
      polNowego[0] <= ( (*it)->Wierz_Glb.pojemnik[1][0]+25) &&
      polNowego[1] <= ( (*it)->Wierz_Glb.pojemnik[0][1]+25) &&
      polNowego[1] >= ( (*it)->Wierz_Glb.pojemnik[2][1]-25)  ){
    
      cout<<"W tym miejscu juz istnieje obiekt !!"<<endl;
    
    czybum=false;
      }

       if(typ==1)
         if( polNowego[0] >= ( (*it)->Wierz_Glb.pojemnik[0][0]-10) &&
      polNowego[0] <= ( (*it)->Wierz_Glb.pojemnik[1][0]+10) &&
      polNowego[1] <= ( (*it)->Wierz_Glb.pojemnik[0][1]+10) &&
      polNowego[1] >= ( (*it)->Wierz_Glb.pojemnik[2][1]-10)  ){
    
      cout<<"W tym miejscu juz istnieje obiekt !!"<<endl;
    
    czybum=false;
      }





     }


  for(ite = roboty.begin(); ite != roboty.end(); ++ite)
     {
       
odleglosc= 
sqrt((polNowego[0]-(*ite)->polozenie[0])*(polNowego[0]-(*ite)->polozenie[0])  +
     (polNowego[1]-(*ite)->polozenie[1])*(polNowego[1]-(*ite)->polozenie[1]));
 

 if( odleglosc <= 20 && odleglosc >= 0 ){
   
     cout<<"W tym miejscu juz istnieje obiekt !!"<<endl;
   
   czybum=false;
 }
     }
  return czybum;
}
