#ifndef _ARTEMIS_DEFS_H
#define _ARTEMIS_DEFS_H

#include <TeensyThreads.h>
#include <support/packetcomm.h>
#include <support/configCosmosKernel.h>

// Sensor Defs
#define ARTEMIS_CURRENT_BEACON_1_COUNT 2
#define ARTEMIS_CURRENT_SENSOR_COUNT 5
#define ARTEMIS_TEMP_SENSOR_COUNT 7
#define AREF_VOLTAGE 3.3

#define MAXQUEUESIZE 50

// Nodes
enum class NODES : uint8_t
{
  GROUND_NODE_ID = 1,
  TEENSY_NODE_ID = 2,
  RPI_NODE_ID = 3,
  PLEIADES_NODE_ID = 4,
};

extern std::map<string, NODES> NodeType;

struct thread_struct
{
  int thread_id;
  uint8_t channel_id;
};

enum TEENSY_PINS // Artemis OBC v4.24
{
  UART4_RXD,
  UART4_TXD,
  T_GPIO2,
  T_GPIO3,
  T_GPIO4,
  T_GPIO5,
  T_GPIO6,
  UART6_RX,
  UART6_TX,
  T_CS1,
  T_CS,
  SPI0_MOSI,
  SPI0_MISO,
  SPI0_SCLK,
  AIN0,
  AIN1,
  SCL1_I2C,
  SDA1_I2C,
  I2C2_SDA,
  I2C2_SCL,
  AIN3,
  AIN4,
  AIN5,
  AIN6,
  I2C1_SCL,
  I2C1_SDA,
  SPI1_D1,
  SPI1_SCLK,
  UART5_TXD,
  UART5_RXD,
  RX_ON,
  TX_ON,
  RADIO_RESET,
  GPS_RSTN,
  UART2_RXD,
  UART2_TXD,
  RPI_ENABLE,
  SDN,
  SPI1_CS1,
  SPI1_D0,
  NIRQ,
  AIN2
};

// Max threads = 16
extern vector<struct thread_struct> thread_list;

// Mutex for Command Queues
extern Threads::Mutex main_queue_mtx;
extern Threads::Mutex astrodev_queue_mtx;
extern Threads::Mutex rfm23_queue_mtx;
extern Threads::Mutex rfm98_queue_mtx;
extern Threads::Mutex pdu_queue_mtx;
extern Threads::Mutex rpi_queue_mtx;

// Command Queues
extern std::deque<PacketComm> main_queue;
extern std::deque<PacketComm> astrodev_queue;
extern std::deque<PacketComm> rfm23_queue;
extern std::deque<PacketComm> rfm98_queue;
extern std::deque<PacketComm> pdu_queue;
extern std::deque<PacketComm> rpi_queue;

// Other Mutex
extern Threads::Mutex spi1_mtx;
extern Threads::Mutex i2c1_mtx;

// Utility Functions
int kill_thread(uint8_t channel_id);
int32_t PushQueue(PacketComm &packet, std::deque<PacketComm> &queue, Threads::Mutex &mtx);
int32_t PullQueue(PacketComm &packet, std::deque<PacketComm> &queue, Threads::Mutex &mtx);

#endif // _ARTEMIS_DEFS_H
