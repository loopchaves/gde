/*
 *  ZeX/OS
 *  Copyright (C) 2007  Tomas 'ZeXx86' Jedrzejek (zexx86@gmail.com)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//system calls.
#include <stubs/gramado.h> 

int close (int fd)
{
	/*
	asm volatile (
		"pushl %%eax;"
		"pushl %%ebx;"
		"pushl %%ecx;"
		"pushl %%edx;"
		"movl $17, %%eax;"
	     	"movl %0, %%ebx;"
	     	"int $0x80;"
		"popl %%edx;"
		"popl %%ecx;"
		"popl %%ebx;"
		"popl %%eax;" :: "g" (fd));
	
	*/
		
    return (int) gramado_system_call ( 17, (unsigned long) fd, (unsigned long) fd, (unsigned long) fd );
}
 
