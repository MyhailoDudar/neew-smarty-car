#ifndef MEDIA_H
#define MEDIA_H

#include "Device.h"
#include <string>

class Media : public Device {
public:
    Media(const std::string& name, int vol);
    void SetVol(int vol);
    int Status();
protected:
    int vol;
};

#endif // MEDIA_H
