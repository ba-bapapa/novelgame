#include"Include.h"

 UserClass::UserClass() {
	 PageFlag = PAGE::TITLE;
	 
}
 
  int UserClass::GetTextSpeed() {
	  int TextSpeed;
/*
	  if (ConfigData.TextSpeed == 0) TextSpeed = 5;
	  if (ConfigData.TextSpeed == 1) TextSpeed = 4;
	  if (ConfigData.TextSpeed == 2) TextSpeed = 3;
	  if (ConfigData.TextSpeed == 3) TextSpeed = 2;
	  if (ConfigData.TextSpeed == 4) */
	  TextSpeed = 1;

	  return TextSpeed;
}