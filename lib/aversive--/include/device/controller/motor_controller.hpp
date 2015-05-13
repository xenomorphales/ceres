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

#ifndef MOTOR_CONTROLLER_HPP
#define MOTOR_CONTROLLER_HPP

#include <device/output.hpp>
#include <device/input.hpp>
#include <filter/feedback_loop_filter.hpp>
#include <filter/filter.hpp>
#include <base/integer.hpp>

template<class Config>
class MotorController : public Output<s32> {
private:
  FeedbackLoopFilter<Config> _loop;
  typename Config::Motor& _mot;
  typename Config::Encoder& _enc;

public:
  MotorController(
		  decltype(_mot)& mot,
		  decltype(_enc)& enc,
		  typename Config::ConsignFilter& cf,
		  typename Config::FeedbackFilter& ff,
		  typename Config::ErrorFilter& ef)
    : _loop(cf, ff, ef), _mot(mot), _enc(enc) {
    
  }

  void setValue(s32 val) {
	const s32 enc = _enc.getValue();
    _loop.setFeedback(enc);
    val = _loop.doFilter(val);
    _mot.setValue(val);
  }
};

#endif//MOTOR_CONTROLLER_HPP

