#ifndef _GPIO_TOOLS_H
#define _GPIO_TOOLS_H

#include <iostream>
#include <fstream>
#include <sstream>

const std::string SYSFS_GPIO_DIR = "/sys/class/gpio";

class CGpio
{
  private:
    int id;
    bool opened;
  protected:
  public:
    CGpio(int num);
    ~CGpio();
    int open(void);
    int close(void);
    int setEdge(std::string edge);
    int setDirection(std::string dir);
    int setValue(int value);
    int getValue(void);
    int getId(void);
    //TODO: poll()
};

#endif
