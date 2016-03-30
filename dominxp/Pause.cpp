#include "Pause.h"
bool run=true;
void PAUSE()
{
	run=false;
}
void RESUME()
{
	run=true;
}
bool RUN()
{
	return run;
}