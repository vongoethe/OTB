/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "otbWrapperApplicationFactory.h"

int otbWrapperApplicationFactory(int argc, char* argv[])
{
  using otb::Wrapper::ApplicationFactory;
  std::list<std::string> list = ApplicationFactory::GetAvailableApplications();

  std::cout << "Available applications :" << std::endl;
  std::list<std::string>::const_iterator it;
  for (it = list.begin(); it != list.end(); ++it)
    {
    std::cout << *it << std::endl;
    }
  return EXIT_SUCCESS;
}
