#include <Windows.h>
#include "Include/Dask64.h"
#include <conio.h>
#include <iostream>

int main(int argc, char ** argv)
{
	I16 cardId = Register_Card(PCI_9111DG, 0);
	if (cardId >= 0)
	{
		std::cout << "Ouverture carte OK" << std::endl;

		AI_9111_Config(cardId, TRIG_INT_PACER, P9111_TRGMOD_SOFT, 0);

		double tension;

		if (AI_VReadChannel(cardId, 0, AD_B_10_V, &tension) < 0)
			std::cout << "Erreur lecture" << std::endl;
		else
		{
			std::cout << "Tension : " << tension << std::endl;
		}

		Release_Card(cardId);
	}

	_getch();

	return 0;
}