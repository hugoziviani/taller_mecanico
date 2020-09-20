#ifndef TALLER_MECANICO_UNIQUEID_H
#define TALLER_MECANICO_UNIQUEID_H

#include <iostream>

class UniqueId {
protected:
    static int nextID;
public:
    int id;
    UniqueId();
    UniqueId(const UniqueId& orig);

    UniqueId& operator=(const UniqueId& orig);

    bool operator==(const UniqueId &rhs) const;

    bool operator<(const UniqueId &rhs) const;

    bool operator>(const UniqueId &rhs) const;

    bool operator<=(const UniqueId &rhs) const;

    bool operator>=(const UniqueId &rhs) const;
};

#endif //TALLER_MECANICO_UNIQUEID_H
