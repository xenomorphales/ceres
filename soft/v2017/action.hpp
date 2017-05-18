#ifndef ACTION_HPP
#define ACTION_HPP

class Action {
public:
  enum State {
    WAIT,
    RUN,
    END,
    ERROR
  };

private:
  State _state;

protected:
  inline void setState(State state) {
    _state = state;
  }

public:
  inline Action(void) : _state(WAIT) {
  }

public:
  inline State state(void) {
    return _state;
  }

public:
  virtual void update(void) = 0;
};

#endif//ACTION_HPP
