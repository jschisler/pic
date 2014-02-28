/* 
 * File:   states.h
 * Author: jschisler
 *
 * Created on February 18, 2014, 3:00 PM
 */

#ifndef STATES_H
#define	STATES_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum PacketStates_s {
    NONE = -1,
    GOT_STX,
    GOT_CMD,
    GOT_DATA,
    PACKET_COMPLETE
} PacketState;

#ifdef	__cplusplus
}
#endif

#endif	/* STATES_H */

