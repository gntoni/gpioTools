#include "gpiotools.h"


CGpio::CGpio(int num)
{
  this->id=num;
}

CGpio::~gpio()
{
}

int CGpio::open(void)
{
  //Export pin
  ofstream gpioFile(SYSFS_GPIO_DIR "/export");
  if (gpioFile.is_open())
  {
    gpioFile << this->id;
    gpioFile.close();
    return 0;  
  }
  else
  {
    std::cout << "Unable to export pin" << std::endl; 
    return -1;
  }
}

int CGpio::close(void)
{
  //Unexport pin
  ofstream gpioFile(SYSFS_GPIO_DIR "/unexport");
  if (gpioFile.is_open())
  {
    gpioFile << this->id;
    gpioFile.close();
    return 0;  
  }
  else
  {
    std::cout << "Unable to unexport pin" << std::endl;
    return -1; 
  }
}

int CGpio::setEdge(std::string edge)
{
  //Set pin edge
  sstream filename;
  filename << SYSFS_GPIO_DIR << "/gpio" << this->id;
  ofstream gpioFile(filename.str());
  if (gpioFile.is_open())
  {
    gpioFile << edge;
    gpioFile.close();
    return 0;  
  }
  else
  {
    std::cout << "Unable to set edge" << std::endl; 
    return -1;
  }
}

int CGpio::setDirection(std::string dir)
{
  //Set pin direction
  sstream filename;
  filename << SYSFS_GPIO_DIR << "/gpio" << this->id;
  ofstream gpioFile(filename.str());
  if (gpioFile.is_open())
  {
    gpioFile << dir;
    gpioFile.close();
    return 0;  
  }
  else
  {
    std::cout << "Unable to set pin direction" << std::endl; 
    return -1;
  }
}

int CGpio::setValue(int value)
{
  //Set pin direction
  sstream filename;
  filename << SYSFS_GPIO_DIR << "/gpio" << this->id;
  ofstream gpioFile(filename.str());
  if (gpioFile.is_open())
  {
    gpioFile << value;
    gpioFile.close();
    return 0;  
  }
  else
  {
    std::cout << "Unable to set edge" << std::endl; 
    return -1;
  }
}

int CGpio::getValue(void)
{
}

int CGpio::getId(void)
{
}
