void setDriveVoltage(float leftVolts, float rightVolts);

void setDriveVelocity(float leftVelo, float rightVelo);

float reduceAngle0to360(float angleDeg);

float reduceAngleMinus180to180(float angleDeg);

void updatePosition();

int positionTrack();

void turn(float angle, float timeout = 0, float settlingerror = 1, float settlingtime = 40, float kp = .3, float ki = .01, float kd = 1, float maxvoltage = 12);

void straightdrive(float x, float y, float timeout = 0, float kp = 1, float ki = 0, float kd = .2, float turnp = 1, float maxvoltage = 11, float settlingerror = 1, float settlingtime = 20);