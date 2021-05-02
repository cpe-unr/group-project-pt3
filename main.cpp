//Group 3 teammates: Caitlin Hibler,
//Final project
//Due Date: May 2, 2021


/** @file */
#include <iostream>
#include "echo.h"
#include "noisegate.h"
#include "normalization.h"
#include "Processor.h"

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main(int argc, char *argv[]){

    	if(argc != 2){
                std::cout << "Correct Usage: " << argv[0] << " <filename>" << std::endl;
        }

        else{
               std::cout << "EYY you did it!" << std::endl; //tester
	}


    return 0;
}
