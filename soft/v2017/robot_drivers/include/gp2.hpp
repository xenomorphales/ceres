#ifndef GP2_HPP
#define GP2_HPP

class GP2 {
private:
  int _id;

private:
  GP2(int id);

public:
  int get(void);

public:
  static GP2 gp2[4];
};

#endif//GP2_HPP
