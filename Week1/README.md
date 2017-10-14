# Тази седмица:
  - Запознаване със средите за разработка - Visual Studio and CodeBlocks
  - Компилация на "Hello World" програма.
  - Дискусия на използваните конструкции.
  - Деклариране на променливи
  - Типове данни
    - int, float (като за начало)
  - Вход/Изход - cin и cout
  - Допълнително
    - Процес на компилация на С++ програми.

# Ресурси към темата:
  - www.learncpp.com: Chapter 0 and Chapter 1
  - http://www.cplusplus.com/doc/tutorial/introduction/
  - C++ Without Fear: Chapter 1 Start Using C++

# Процес на компилация на C++ програми:

По даден C++ файл 'sample.cpp', стъпките за получаване на изпълнима програма са:

1. Preprocessor:

   В 'sample.cpp' добавя кода на include-натите header file-ове,
   , замества символни констани дефинирани чрез #define:

     'sample_extended.cpp'

2. Compiler:

   Компилира 'sample_extended.cpp' в код на асемблерен език за текущата платформа:

      'sample_assembly.s'


3. Assembler:

   Превръща 'sample_assembly.s' в object file за платформата:

      'sample_object_file.o'

4. Linker:

   Свързва 'sample_object_file.o' с object file-овете на използвани библиотечни
   функции и се превръща в изпълнима програма.