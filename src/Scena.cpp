#include "Scena.hh"

void Scena::dodajObiektGraf(TypObiektu typ, Wektor2D wsp, Wektor2D rozm)
{
	switch (typ)
	{
		case TO_Robot:
		{
			std::shared_ptr<Trasa> trs = Fabryka_Ob::ZbudujObiektTrasa();
			LST.push_back(trs);
			std::shared_ptr<Robot> rbt = Fabryka_Ob::ZbudujObiektRobot( wsp, trs);
			LST.push_back(rbt);
			LST_rbt.push_back(rbt);
			
		}
		break;

		case TO_Przeszkoda:
		{
			LST.push_back(Fabryka_Ob::ZbudujObiektPrzeszkoda(  wsp, rozm ));
		}
		break;

		case TO_Sciezka:
			LST.push_back(Fabryka_Ob::ZbudujObiektTrasa());
		break;
	}
}

Scena::Scena (PzG::LaczeDoGNUPlota  lcz)
{
	 std::shared_ptr<Trasa> wTrs_1(new Trasa);
	 std::shared_ptr<Trasa> wTrs_2(new Trasa);
	 std::shared_ptr<Trasa> wTrs_3(new Trasa);

	 std::shared_ptr<Robot> wRob_1(new Robot(100,-100, wTrs_1));
	 std::shared_ptr<Robot> wRob_2(new Robot(0,0, wTrs_2));
	 std::shared_ptr<Robot> wRob_3(new Robot(100,150, wTrs_3));

	 std::shared_ptr<Obiekt_Graf> wPrz_1(new Przeszkoda(-240, -50, 180, 90));
	 std::shared_ptr<Obiekt_Graf> wPrz_2(new Przeszkoda(160, -50, 90, 200));
	 std::shared_ptr<Obiekt_Graf> wPrz_3(new Przeszkoda(-90, 210, 200, 30));

	 

	 LST.push_back(wRob_1);
	 LST.push_back(wRob_2);
	 LST.push_back(wRob_3);

	 LST.push_back(wPrz_1);
	 LST.push_back(wPrz_2);
	 LST.push_back(wPrz_3);

	 LST.push_back(wTrs_1);
	 LST.push_back(wTrs_2);
	 LST.push_back(wTrs_3);

	 LST_rbt.push_back(wRob_1);
	 LST_rbt.push_back(wRob_2);
	 LST_rbt.push_back(wRob_3);

	Lacze = lcz;
}

void Scena::ZapisWspolrzednychDoStrumienia_Scena( std::ostream & StrmWy)                                       
{ 
	for( const std::shared_ptr<Obiekt_Graf> obGraf : LST)
	StrmWy << *obGraf <<std::endl<<std::endl;
}

std::shared_ptr<Robot> Scena::zwrocWskRobota( int id )
{
	std::shared_ptr<Robot> lala;
	int licz=0;
			for( std::shared_ptr<Robot> robo : LST_rbt)	
			{
				if(licz == id) 
				{
						return robo;
				}
				licz ++;
			}
		return lala;
}

void Scena::rysujTraseRobota (int id)
{
	int licz=0;
			for( std::shared_ptr<Robot> rbt : LST_rbt)	
			{
				if(licz == id) 
				{
						rbt->RysujTrase(*(rbt->WezWskNaTrase()));
				}
				licz ++;
			}
}

void Scena::obrotRobota(double kat,int id)
{
	
  for(int i = 0; i<10; i++)
  {
		zwrocWskRobota(id)->Obrot(kat/10);
		sleep(0.2);
		wyswietlScene();
  }
}

bool Scena::ruchRobota(double dl_kroku, int id)
{
	int licznik;	

  for(int i = 0; i<zwrocWskRobota(id)->wezPredkosc(); i++)
    {

					licznik = 0;
					for( std::shared_ptr<Obiekt_Graf> prz : LST)
					{	
							if(prz->czyKolizja( zwrocWskRobota(id)->wezPozycje(), promien ))
							{
								licznik++;
							}

							if(licznik > 1) 
							{
								rysujTraseRobota(id);
								wyswietlScene();
								return true;
							}
					}
					rysujTraseRobota(id);
					zwrocWskRobota(id)->RuchWPrzod(dl_kroku/zwrocWskRobota(id)->wezPredkosc());
					sleep(0.1);
					wyswietlScene();
    }
		 rysujTraseRobota(id);
     wyswietlScene();
		return false;
}



bool Scena::ZapisWspolrzednychDoPliku( const char *sNazwaPliku)                         
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  ZapisWspolrzednychDoStrumienia_Scena(StrmPlikowy);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

void Scena::wyswietlScene()
{
  if (!ZapisWspolrzednychDoPliku("scena.dat")) return;
  Lacze.Rysuj();
}

void Scena::zmienPredkoscRobota(int PR, int id)
{ 
	zwrocWskRobota(id)->zmienPredkosc(PR);
}

void Scena::przesuniecie (Wektor2D Wek)
{
	for( std::shared_ptr<Obiekt_Graf> obiekt : LST)
	{
		obiekt->Translacja(Wek);
	}

	for( std::shared_ptr<Robot> rbt : LST_rbt)
	{
		rbt->zapiszWekPoz(Wek);
	}
	wyswietlScene();
	// for( std::shared_ptr<Obiekt_Graf> obiekt : LST)
	// {
	// 	obiekt->zapiszWekGlob(Wek);
	// }
	// wyswietlScene();
}

void Scena::wyswietlPozycjeRobotow(std::ostream & str)
{
      for(unsigned int i=0;i<LST_rbt.size();i++)
      str<<" Robot "<<i+1<<".    Wspolrzedne: "<< wezPozRob(i) <<std::endl;
      str<<std::endl;
}















