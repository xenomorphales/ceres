#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <singleton.hpp>
#include <service.hpp>

class Strategy : public Singleton<Strategy>, public Service {
public:
  Strategy(void);
};

#endif//STRATEGY_HPP
