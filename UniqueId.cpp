#include "UniqueId.h"

UniqueId::UniqueId() {
    id = ++nextID;
}

UniqueId::UniqueId(const UniqueId& orig) {
    id = orig.id;
}

UniqueId& UniqueId::operator=(const UniqueId& orig) {
    id = orig.id;
    return(*this);
}
bool UniqueId::operator==(const UniqueId &rhs) const {
    return id == rhs.id;
}
bool UniqueId::operator<(const UniqueId &rhs) const {
    return id < rhs.id;
}
bool UniqueId::operator>(const UniqueId &rhs) const {
    return rhs < *this;
}
bool UniqueId::operator<=(const UniqueId &rhs) const {
    return !(rhs < *this);
}
bool UniqueId::operator>=(const UniqueId &rhs) const {
    return !(*this < rhs);
}
