/* 
 * File:   packet.h
 * Author: jschisler
 *
 * Created on February 18, 2014, 2:52 PM
 */

#ifndef PACKET_H
#define	PACKET_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum PacketBytes_e {
    NUL = 0x00,
    SOH = 0x01,
    STX = 0x02,
    ETX = 0x03,
    EOT = 0x04,
    ENQ = 0x05,
    ACK = 0x06
} PacketByte;

volatile union {
    struct Packet_s {
        BYTE stx;
        uint16_t address;
        BYTE cmd[4];
        BYTE data[4];
        BYTE etx;
    };
    BYTE data[12];
} Packet;

#ifdef	__cplusplus
}
#endif

#endif	/* PACKET_H */

