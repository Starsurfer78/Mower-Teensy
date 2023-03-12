void RobotControl::set_speed(int speed_left, int speed_right) {
  motor_left.set_speed(speed_left);
  motor_right.set_speed(-speed_right);
}

void RobotControl::drive_forward(int speed) {
  set_speed(speed, speed);
}

void RobotControl::drive_backward(int speed) {
  set_speed(-speed, -speed);
}

void RobotControl::turn_left(int speed) {
  set_speed(-speed, speed);
}

void RobotControl::turn_right(int speed) {
  set_speed(speed, -speed);
}

void RobotControl::stop() {
  set_speed(0, 0);
}

void RobotControl::update() {
  update_encoders();
  update_bumpers();
}

void RobotControl::update_encoders() {
  int encoder_left_count = encoder_left.read();
  int encoder_right_count = encoder_right.read();

  int encoder_left_diff = encoder_left_count - _encoder_left_count;
  int encoder_right_diff = encoder_right_count - _encoder_right_count;

  _encoder_left_count = encoder_left_count;
  _encoder_right_count = encoder_right_count;

  _distance_left += encoder_left_diff * WHEEL_CIRCUMFERENCE / ENCODER_COUNTS_PER_REVOLUTION;
  _distance_right += encoder_right_diff * WHEEL_CIRCUMFERENCE / ENCODER_COUNTS_PER_REVOLUTION;

  _velocity_left = encoder_left_diff / ENCODER_COUNTS_PER_REVOLUTION * WHEEL_CIRCUMFERENCE / (millis() - _last_encoder_update);
  _velocity_right = encoder_right_diff / ENCODER_COUNTS_PER_REVOLUTION * WHEEL_CIRCUMFERENCE / (millis() - _last_encoder_update);
  
  _last_encoder_update = millis();
}

void RobotControl::update_bumpers() {
  if (_bumper_left_triggered) {
    _bumper_left_triggered = false;
    _bumper_left_debouncing = true;
    _last_bumper_update = millis();
  }

  if (_bumper_right_triggered) {
    _bumper_right_triggered = false;
    _bumper_right_debouncing = true;
    _last_bumper_update = millis();
  }

  if (_bumper_left_debouncing && millis() - _last_bumper_update > BUMPER_DEBOUNCE_TIME) {
    _bumper_left_debouncing = false;
    if (digitalRead(PIN_BUMPER_LEFT) == LOW) {
      _bumper_left_pressed = true;
    }
  }

  if (_bumper_right_debouncing && millis() - _last_bumper_update > BUMPER_DEBOUNCE_TIME) {
    _bumper_right_debouncing = false;
    if (digitalRead(PIN_BUMPER_RIGHT) == LOW) {
      _bumper_right_pressed = true;
    }
  }
}

bool RobotControl::bumper_left_triggered() {
  return _bumper_left_triggered;
}

bool RobotControl::bumper_right_triggered() {
  return _bumper_right_triggered;
}

bool RobotControl::bumper_left_pressed() {
  if (_bumper_left_pressed) {
    _bumper_left_pressed = false;
    return true;
  } else {
    return false;
  }
}

bool RobotControl::bumper_right_pressed() {
  if (_bumper_right_pressed) {
    _bumper_right_pressed = false;
    return true;
  } else {
    return false;
  }
}

float RobotControl::distance_left() {
  return _distance_left;
}

float RobotControl::distance_right() {
  return _distance_right;
}

float RobotControl::velocity_left() {
  return _velocity_left;
}

