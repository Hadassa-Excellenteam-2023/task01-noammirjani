#pragma once
#include <iostream>
#include "Test.h"
#include "Vector.h"

int main(){

   try{
         Test test;
         test.testVector();
         test.testStack();
   }
   catch(std::exception& e){
       std::cerr << e.what() << std::endl;
   }

	return EXIT_SUCCESS;
}