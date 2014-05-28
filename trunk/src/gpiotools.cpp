#include "gpiotools.h"


CGpio::CGpio(int num)
{
  this->id=num;
}

CGpio::~CGpio()
{
}

int CGpio::open(void)
{
  //Export pin
  std::stringstream filename;
  filename << SYSFS_GPIO_DIR << "/export";
  std::ofstream gpioFile(filename.str().c_str());
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
  std::stringstream filename;
  filename << SYSFS_GPIO_DIR << "/unexport";
  std::ofstream gpioFile(filename.str().c_str());
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
  std::stringstream filename;
  filename << SYSFS_GPIO_DIR << "/gpio" << this->id;
  std::ofstream gpioFile(filename.str().c_str());
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
  std::stringstream filename;
  filename << SYSFS_GPIO_DIR << "/gpio" << this->id;
  std::ofstream gpioFile(filename.str().c_str());
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
  std::stringstream filename;
  filename << SYSFS_GPIO_DIR << "/gpio" << this->id;
  std::ofstream gpioFile(filename.str().c_str());
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
  return 0;
}

int CGpio::getId(void)
{
  return 0;
}
