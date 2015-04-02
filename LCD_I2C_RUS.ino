#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


wchar_t loadedLetters[8];
wchar_t NOT_LOADED = L'?';

// Русский шрифт недостающих букв
byte rusLetterB[8]	 	= {0x1F, 0x11, 0x10, 0x1E, 0x11, 0x11, 0x1E, 0};	 	 //Б
byte rusLetterB_small[8]	= {0x0, 0x0, 0x1E, 0x10, 0x1E, 0x11, 0x1E, 0};	 	         //б
byte rusLetterV_small[8]	= {0x0, 0x0, 0x1E, 0x11, 0x1E, 0x11, 0x1E, 0};	 	         //в
byte rusLetterG[8]	 	= {0x1F, 0x11, 0x10, 0x10, 0x10, 0x10, 0x10, 0};	 	 //Г
byte rusLetterG_small[8]	= {0x0, 0x0, 0x1E, 0x10, 0x10, 0x10, 0x10, 0};	 	         //г
byte rusLetterD[8]	 	= {0x0F, 0x05, 0x05, 0x05, 0x09, 0x11, 0x1F, 0x11};              //Д
byte rusLetterD_small[8] 	= {0x00, 0x00, 0x0F, 0x05, 0x09, 0x11, 0x1F, 0x11};              //д
byte rusLetterGH[8]	        = {0x15, 0x15, 0x15, 0x0E, 0x15, 0x15, 0x15, 0};	 	 //ж
byte rusLetterGH_small[8]       = {0x00, 0x00, 0x15, 0x15, 0x0E, 0x15, 0x15, 0};	 	 //Ж
byte rusLetterZ_small[8]        = {0x00, 0x00, 0x0F, 0x01, 0x0F, 0x01, 0x0F, 0};	 	 //з
byte rusLetterI[8]	 	= {0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0};	 	 //и
byte rusLetterI_small[8] 	= {0x00, 0x00, 0x11, 0x13, 0x15, 0x19, 0x11, 0};	 	 //И
byte rusLetterIY[8]	        = {0x0A, 0x15, 0x13, 0x15, 0x19, 0x11, 0x11, 0};	 	 //Й
byte rusLetterIY_small[8]       = {0x00, 0x0A, 0x15, 0x13, 0x15, 0x19, 0x11, 0};	 	 //Й
byte rusLetterK_small[8]	= {0x00, 0x00, 0x12, 0x14, 0x18, 0x14, 0x12, 0};	 	 //к
byte rusLetterL[8]	 	= {0x0F, 0x05, 0x05, 0x05, 0x05, 0x15, 0x09, 0};	 	 //Л
byte rusLetterL_small[8]	= {0x00, 0x00, 0x07, 0x05, 0x05, 0x15, 0x09, 0};	 	 //л
byte rusLetterM_small[8]	= {0x00, 0x00, 0x11, 0x1B, 0x15, 0x15, 0x11, 0};	 	 //м
byte rusLetterN_small[8]	= {0x00, 0x00, 0x12, 0x12, 0x1E, 0x12, 0x12, 0};	 	 //н
byte rusLetterP[8]	 	= {0x1F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0};	 	 //П
byte rusLetterP_small[8] 	= {0x00, 0x00, 0x1E, 0x12, 0x12, 0x12, 0x12, 0};	 	 //п
byte rusLetterT_small[8] 	= {0x00, 0x00, 0x1F, 0x04, 0x04, 0x04, 0x04, 0};	 	 //т
byte rusLetterY[8]	 	= {0x11, 0x11, 0x11, 0x0F, 0x01, 0x01, 0x0E, 0};	 	 //У
byte rusLetterF[8]	 	= {0x04, 0x0E, 0x15, 0x15, 0x15, 0x0E, 0x04, 0};	 	 //Ф
byte rusLetterF_small[8] 	= {0x00, 0x00, 0x04, 0x0E, 0x15, 0x0E, 0x04, 0};	 	 //ф
byte rusLetterC[8]	 	= {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F, 1};	 	 //Ц
byte rusLetterC_small[8] 	= {0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1F, 1};	 	 //ц
byte rusLetterCH[8]	        = {0x11, 0x11, 0x11, 0x0F, 0x01, 0x01, 0x01, 0};	 	 //Ч
byte rusLetterCH_small[8]	= {0x00, 0x00, 0x12, 0x12, 0x0E, 0x02, 0x02, 0};	 	 //ч
byte rusLetterSH[8]	        = {0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x1F, 0};	 	 //Ш
byte rusLetterSH_small[8]       = {0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x1F, 0};	 	 //ш
byte rusLetterSCH[8]            = {0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x1F, 1};	 	 //Щ
byte rusLetterSCH_small[8]      = {0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x1F, 1};	 	 //щ
byte rusLetterTZN[8]            = {0x18, 0x08, 0x08, 0x0E, 0x09, 0x09, 0x0E, 0};	 	 //Ъ
byte rusLetterTZN_small[8]      = {0x00, 0x00, 0x18, 0x08, 0x0E, 0x09, 0x0E, 0};	 	 //ъ
byte rusLetterEI[8]             = {0x11, 0x11, 0x11, 0x19, 0x15, 0x15, 0x19, 0};	 	 //Ы
byte rusLetterEI_small[8]       = {0x00, 0x00, 0x11, 0x11, 0x19, 0x15, 0x19, 0};	 	 //ы
byte rusLetterMZN_small[8]      = {0x00, 0x00, 0x08, 0x08, 0x0E, 0x09, 0x0E, 0};	 	 //ь
byte rusLetterEE[8]	        = {0x0E, 0x11, 0x01, 0x07, 0x01, 0x11, 0x0E, 0};	 	 //Э
byte rusLetterEE_small[8]       = {0x00, 0x00, 0x0E, 0x01, 0x07, 0x01, 0x0E, 0};	 	 //э
byte rusLetterYU[8]	        = {0x12, 0x15, 0x15, 0x1D, 0x15, 0x15, 0x12, 0};	 	 //Ю
byte rusLetterYU_small[8]       = {0x00, 0x00, 0x12, 0x15, 0x1D, 0x15, 0x12, 0};	 	 //ю
byte rusLetterYA[8]	        = {0x0F, 0x11, 0x11, 0x0F, 0x05, 0x09, 0x11, 0};	 	 //Я
byte rusLetterYA_small[8]       = {0x00, 0x00, 0x0F, 0x11, 0x0F, 0x09, 0x11, 0};	 	 //я

// Функция ищет символ среди дополнительно загруженных (максимум 8),
// при необходимости и если есть место символ загружается в LCD
char loadAndGetChar(wchar_t c, uint8_t *letterMap) {
  int ix = 9;  // От 1 до 9, нельзя использовать 0-й символ(конца строки)
  //Ищем букву в уже загруженных символах
  for (int i = 1; i < ix; i++) {
    if (c == loadedLetters[i - 1]) {
      return char(i);
    } else if (loadedLetters[i - 1] == NOT_LOADED) {
      ix = i;
      break;
    }
  }
  //Если загружено 8 символов, то выводим пробел
  if (ix == 9) {
    return (char)NOT_LOADED;
  }
  //Загружаем новый символ в LCD
  lcd.createChar(ix, letterMap);
  loadedLetters[ix - 1] = c;
  return char(ix);
}

// Функция возвращает локализованный символ или NOT_LOADED,
// если не хватает места в памяти под дополнительные символы
char getTranslatedLetter(wchar_t c) {
  switch (c) {
    case L'А': return 'A';
    case L'а': return 'a';
    case L'Б': return loadAndGetChar(c, rusLetterB);
    case L'б': return loadAndGetChar(c, rusLetterB_small);
    case L'В': return 'B';
    case L'в': return loadAndGetChar(c, rusLetterV_small);
    case L'Г': return loadAndGetChar(c, rusLetterG);
    case L'г': return loadAndGetChar(c, rusLetterG_small);
    case L'Д': return loadAndGetChar(c, rusLetterD);
    case L'д': return loadAndGetChar(c, rusLetterD_small);
    case L'Е': return 'E';
    case L'е': return 'e';
    case L'Ё': return 'E';
    case L'ё': return 'e';
    case L'Ж': return loadAndGetChar(c, rusLetterGH);
    case L'ж': return loadAndGetChar(c, rusLetterGH_small);
    case L'З': return '3';
    case L'з': return loadAndGetChar(c, rusLetterZ_small);
    case L'И': return loadAndGetChar(c, rusLetterI);
    case L'и': return loadAndGetChar(c, rusLetterI_small);
    case L'Й': return loadAndGetChar(c, rusLetterIY);
    case L'й': return loadAndGetChar(c, rusLetterIY_small);
    case L'К': return 'K';
    case L'к': return loadAndGetChar(c, rusLetterK_small);
    case L'Л': return loadAndGetChar(c, rusLetterL);
    case L'л': return loadAndGetChar(c, rusLetterL_small);
    case L'М': return 'M';
    case L'м': return loadAndGetChar(c, rusLetterM_small);
    case L'Н': return 'H';
    case L'н': return loadAndGetChar(c, rusLetterN_small);
    case L'О': return 'O';
    case L'о': return 'o';
    case L'П': return loadAndGetChar(c, rusLetterP);
    case L'п': return loadAndGetChar(c, rusLetterP_small);
    case L'Р': return 'P';
    case L'р': return 'p';
    case L'С': return 'C';
    case L'с': return 'c';
    case L'Т': return 'T';
    case L'т': return loadAndGetChar(c, rusLetterT_small);
    case L'У': return loadAndGetChar(c, rusLetterY);
    case L'у': return 'y';
    case L'Ф': return loadAndGetChar(c, rusLetterF);
    case L'ф': return loadAndGetChar(c, rusLetterF_small);
    case L'Х': return 'X';
    case L'х': return 'x';
    case L'Ц': return loadAndGetChar(c, rusLetterC);
    case L'ц': return loadAndGetChar(c, rusLetterC_small);
    case L'Ч': return loadAndGetChar(c, rusLetterCH);
    case L'ч': return loadAndGetChar(c, rusLetterCH_small);
    case L'Ш': return loadAndGetChar(c, rusLetterSH);
    case L'ш': return loadAndGetChar(c, rusLetterSH_small);
    case L'Щ': return loadAndGetChar(c, rusLetterSCH);
    case L'щ': return loadAndGetChar(c, rusLetterSCH_small);
    case L'Ъ': return loadAndGetChar(c, rusLetterTZN);
    case L'ъ': return loadAndGetChar(c, rusLetterTZN_small);
    case L'Ы': return loadAndGetChar(c, rusLetterEI);
    case L'ы': return loadAndGetChar(c, rusLetterEI_small);
    case L'Ь': return 'b';
    case L'ь': return loadAndGetChar(c, rusLetterMZN_small);
    case L'Э': return loadAndGetChar(c, rusLetterEE);
    case L'э': return loadAndGetChar(c, rusLetterEE_small);
    case L'Ю': return loadAndGetChar(c, rusLetterYU);
    case L'ю': return loadAndGetChar(c, rusLetterYU_small);
    case L'Я': return loadAndGetChar(c, rusLetterYA);
    case L'я': return loadAndGetChar(c, rusLetterYA_small);
    default: return c;
  }
}

// Функция принимает верхнюю и нижнюю строку для вывода на дисплей
// (!) Принимает wchar_t, ибо для русских букв нужно по два байта
void printToScreen(wchar_t *st_f, wchar_t *st_s) {
  for (int i = 0; i < 8; i++)
    loadedLetters[i] = NOT_LOADED;
  
  char res[17];
  for (int i = 0; i < 2; i++) {
    int ix = 0;
    while (*st_f != L'\0') {
      char c = getTranslatedLetter(*st_f++);
      res[ix++] = c;
    }
    res[ix] = '\0';
    lcd.setCursor(0, i);
    lcd.print(res);
    st_f = st_s;
  }
}


void setup() {
  Serial.begin(9600);
  Serial.println("Setup started");
  Wire.begin();
  lcd.init();
  lcd.backlight();

  printToScreen(L"Привет, мир!", L"  По-русски :D");

  Serial.println("Setup completed");
}

void loop() {
  // code here
}
