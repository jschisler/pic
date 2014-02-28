/* 
 * File:   commands.h
 * Author: jschisler
 *
 * Created on February 18, 2014, 3:18 PM
 */

#ifndef COMMANDS_H
#define	COMMANDS_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum Commands_e {
    CMD_STATUS = 0x01,
    CMD_INFO = 0x02,
    CMD_CAPABILITES = 0x03,
    CMD_FIRE_PHASER = 0x04,
    CMD_FIRE_TORPEDO = 0x05
} Command;

#ifdef	__cplusplus
}
#endif

#endif	/* COMMANDS_H */

