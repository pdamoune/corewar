#include "../../includes/op.h"

int		is_labelchars(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'));
}
