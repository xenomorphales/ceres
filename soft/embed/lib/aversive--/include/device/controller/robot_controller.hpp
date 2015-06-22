/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ROBOT_CONTROLLER_HPP
#define ROBOT_CONTROLLER_HPP

#include <device/output.hpp>
#include <device/input.hpp>
#include <filter/feedback_loop_filter.hpp>
#include <base/integer.hpp>
#include <math/vect.hpp>

template<class Config>
class RobotController : public Output<Vect<2, s32>> {
 private:
  FeedbackLoopFilter<typename Config::DConfig> _loop_d;
  FeedbackLoopFilter<typename Config::AConfig> _loop_a;
  typename Config::LMotor& _mot_l;
  typename Config::RMotor& _mot_r;
  typename Config::Odometer& _odo;
  
  typedef typename Config::DConfig::ConsignFilter CFD;
  typedef typename Config::DConfig::FeedbackFilter FFD;
  typedef typename Config::DConfig::ErrorFilter EFD;

  typedef typename Config::AConfig::ConsignFilter CFA;
  typedef typename Config::AConfig::FeedbackFilter FFA;
  typedef typename Config::AConfig::ErrorFilter EFA;

 public:
  RobotController(
		  decltype(_mot_l)& mot_l, decltype(_mot_r)& mot_r, decltype(_odo)& odo,
		  CFD& cfd, FFD& ffd, EFD& efd,
		  CFA& cfa, FFA& ffa, EFA& efa) :
    _loop_d(cfd, ffd, efd), _loop_a(cfa, ffa, efa), _mot_l(mot_l), _mot_r(mot_r), _odo(odo) {}
  
  void setValue(Vect<2, s32> val) {
    Vect<2, s32> fb(_odo.getValue());

    _loop_d.setFeedback(fb.coord(0));
    _loop_a.setFeedback(fb.coord(1));

    s32 corr_d = _loop_d.doFilter(val.coord(0));
    s32 corr_a = _loop_a.doFilter(val.coord(1));
    
    _mot_l.setValue(corr_d + corr_a/2);
    _mot_r.setValue(corr_d - corr_a/2);
  }
};

#endif//ROBOT_CONTROLLER_HPP

