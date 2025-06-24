#ifndef ErrorManager_CPP
#define ErrorManager_CPP

#include <string>
#include <iomanip>

#define ErrorSet errorReturn( 
#define CallError ); return 0;

// Код взятый из интернета на преобразование числа в строку с форматом "0xXXXX"
std::string intToHexString(int value) {
  std::stringstream stream;
  stream << "0x" << std::setw(4) << std::setfill('0') << std::hex << value;
  return stream.str();
}

void errorReturn(int id) { // Функция использует внешний vbs скрипт для вывода текста ошибки (название файла error.vbs)
    switch (id) { // Перебор возможных ошибок
        case 0x0000:
            system("cscript error.vbs \"0x0000 - Test error\"");
            break;
        case 0x0001:
            system("cscript error.vbs \"0x0001 - GLFW not initialized\"");
            break;
        case 0x0002:
            system("cscript error.vbs \"0x0002 - Window not created\"");
            break;
        default: // Если ошибка иная вывод что она неизвестная
            string errorCMD = "cscript error.vbs \"";
            errorCMD += intToHexString(id);
            errorCMD += " - Unknown error\"";
            system(errorCMD.c_str());
            break;
    }
}

#endif