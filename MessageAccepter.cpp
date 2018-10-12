
#include "MessageAccepter.hpp"

std::string MessageAccepter::RecieveMessage() {
    if(_num==0){
        _num++;
        return "start";
    }
    else{
        return "end";
    }

}
