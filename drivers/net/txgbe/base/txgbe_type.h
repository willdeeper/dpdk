/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2015-2020
 */

#ifndef _TXGBE_TYPE_H_
#define _TXGBE_TYPE_H_

#define TXGBE_LINK_UP_TIME	90 /* 9.0 Seconds */

#define TXGBE_ALIGN				128 /* as intel did */

#include "txgbe_status.h"
#include "txgbe_osdep.h"
#include "txgbe_devids.h"

enum txgbe_eeprom_type {
	txgbe_eeprom_unknown = 0,
	txgbe_eeprom_spi,
	txgbe_eeprom_flash,
	txgbe_eeprom_none /* No NVM support */
};

enum txgbe_mac_type {
	txgbe_mac_unknown = 0,
	txgbe_mac_raptor,
	txgbe_mac_raptor_vf,
	txgbe_num_macs
};

enum txgbe_phy_type {
	txgbe_phy_unknown = 0,
	txgbe_phy_none,
	txgbe_phy_tn,
	txgbe_phy_aq,
	txgbe_phy_ext_1g_t,
	txgbe_phy_cu_mtd,
	txgbe_phy_cu_unknown,
	txgbe_phy_qt,
	txgbe_phy_xaui,
	txgbe_phy_nl,
	txgbe_phy_sfp_tyco_passive,
	txgbe_phy_sfp_unknown_passive,
	txgbe_phy_sfp_unknown_active,
	txgbe_phy_sfp_avago,
	txgbe_phy_sfp_ftl,
	txgbe_phy_sfp_ftl_active,
	txgbe_phy_sfp_unknown,
	txgbe_phy_sfp_intel,
	txgbe_phy_qsfp_unknown_passive,
	txgbe_phy_qsfp_unknown_active,
	txgbe_phy_qsfp_intel,
	txgbe_phy_qsfp_unknown,
	txgbe_phy_sfp_unsupported, /* Enforce bit set with unsupported module */
	txgbe_phy_sgmii,
	txgbe_phy_fw,
	txgbe_phy_generic
};

/*
 * SFP+ module type IDs:
 *
 * ID	Module Type
 * =============
 * 0	SFP_DA_CU
 * 1	SFP_SR
 * 2	SFP_LR
 * 3	SFP_DA_CU_CORE0 - chip-specific
 * 4	SFP_DA_CU_CORE1 - chip-specific
 * 5	SFP_SR/LR_CORE0 - chip-specific
 * 6	SFP_SR/LR_CORE1 - chip-specific
 */
enum txgbe_sfp_type {
	txgbe_sfp_type_unknown = 0,
	txgbe_sfp_type_da_cu,
	txgbe_sfp_type_sr,
	txgbe_sfp_type_lr,
	txgbe_sfp_type_da_cu_core0,
	txgbe_sfp_type_da_cu_core1,
	txgbe_sfp_type_srlr_core0,
	txgbe_sfp_type_srlr_core1,
	txgbe_sfp_type_da_act_lmt_core0,
	txgbe_sfp_type_da_act_lmt_core1,
	txgbe_sfp_type_1g_cu_core0,
	txgbe_sfp_type_1g_cu_core1,
	txgbe_sfp_type_1g_sx_core0,
	txgbe_sfp_type_1g_sx_core1,
	txgbe_sfp_type_1g_lx_core0,
	txgbe_sfp_type_1g_lx_core1,
	txgbe_sfp_type_not_present = 0xFFFE,
	txgbe_sfp_type_not_known = 0xFFFF
};

enum txgbe_media_type {
	txgbe_media_type_unknown = 0,
	txgbe_media_type_fiber,
	txgbe_media_type_fiber_qsfp,
	txgbe_media_type_copper,
	txgbe_media_type_backplane,
	txgbe_media_type_cx4,
	txgbe_media_type_virtual
};

/* PCI bus types */
enum txgbe_bus_type {
	txgbe_bus_type_unknown = 0,
	txgbe_bus_type_pci,
	txgbe_bus_type_pcix,
	txgbe_bus_type_pci_express,
	txgbe_bus_type_internal,
	txgbe_bus_type_reserved
};

/* PCI bus speeds */
enum txgbe_bus_speed {
	txgbe_bus_speed_unknown	= 0,
	txgbe_bus_speed_33	= 33,
	txgbe_bus_speed_66	= 66,
	txgbe_bus_speed_100	= 100,
	txgbe_bus_speed_120	= 120,
	txgbe_bus_speed_133	= 133,
	txgbe_bus_speed_2500	= 2500,
	txgbe_bus_speed_5000	= 5000,
	txgbe_bus_speed_8000	= 8000,
	txgbe_bus_speed_reserved
};

/* PCI bus widths */
enum txgbe_bus_width {
	txgbe_bus_width_unknown	= 0,
	txgbe_bus_width_pcie_x1	= 1,
	txgbe_bus_width_pcie_x2	= 2,
	txgbe_bus_width_pcie_x4	= 4,
	txgbe_bus_width_pcie_x8	= 8,
	txgbe_bus_width_32	= 32,
	txgbe_bus_width_64	= 64,
	txgbe_bus_width_reserved
};

struct txgbe_hw;

/* Bus parameters */
struct txgbe_bus_info {
	s32 (*get_bus_info)(struct txgbe_hw *hw);
	void (*set_lan_id)(struct txgbe_hw *hw);

	enum txgbe_bus_speed speed;
	enum txgbe_bus_width width;
	enum txgbe_bus_type type;

	u16 func;
	u8 lan_id;
	u16 instance_id;
};

/* iterator type for walking multicast address lists */
typedef u8* (*txgbe_mc_addr_itr) (struct txgbe_hw *hw, u8 **mc_addr_ptr,
				  u32 *vmdq);

struct txgbe_link_info {
	s32 (*read_link)(struct txgbe_hw *hw, u8 addr, u16 reg, u16 *val);
	s32 (*read_link_unlocked)(struct txgbe_hw *hw, u8 addr, u16 reg,
				  u16 *val);
	s32 (*write_link)(struct txgbe_hw *hw, u8 addr, u16 reg, u16 val);
	s32 (*write_link_unlocked)(struct txgbe_hw *hw, u8 addr, u16 reg,
				   u16 val);

	u8 addr;
};

struct txgbe_rom_info {
	s32 (*init_params)(struct txgbe_hw *hw);
	s32 (*read16)(struct txgbe_hw *hw, u32 offset, u16 *data);
	s32 (*readw_sw)(struct txgbe_hw *hw, u32 offset, u16 *data);
	s32 (*readw_buffer)(struct txgbe_hw *hw, u32 offset, u32 words,
			    void *data);
	s32 (*read32)(struct txgbe_hw *hw, u32 addr, u32 *data);
	s32 (*read_buffer)(struct txgbe_hw *hw, u32 addr, u32 len, void *data);
	s32 (*write16)(struct txgbe_hw *hw, u32 offset, u16 data);
	s32 (*writew_sw)(struct txgbe_hw *hw, u32 offset, u16 data);
	s32 (*writew_buffer)(struct txgbe_hw *hw, u32 offset, u32 words,
			     void *data);
	s32 (*write32)(struct txgbe_hw *hw, u32 addr, u32 data);
	s32 (*write_buffer)(struct txgbe_hw *hw, u32 addr, u32 len, void *data);
	s32 (*validate_checksum)(struct txgbe_hw *hw, u16 *checksum_val);
	s32 (*update_checksum)(struct txgbe_hw *hw);
	s32 (*calc_checksum)(struct txgbe_hw *hw);

	enum txgbe_eeprom_type type;
	u32 semaphore_delay;
	u16 word_size;
	u16 address_bits;
	u16 word_page_size;
	u16 ctrl_word_3;

	u32 sw_addr;
};

struct txgbe_flash_info {
	u32 semaphore_delay;
	u32 dword_size;
	u16 address_bits;
};

#define TXGBE_FLAGS_DOUBLE_RESET_REQUIRED	0x01
struct txgbe_mac_info {
	s32 (*init_hw)(struct txgbe_hw *hw);
	s32 (*reset_hw)(struct txgbe_hw *hw);
	s32 (*start_hw)(struct txgbe_hw *hw);
	s32 (*stop_hw)(struct txgbe_hw *hw);
	s32 (*clear_hw_cntrs)(struct txgbe_hw *hw);
	s32 (*get_mac_addr)(struct txgbe_hw *hw, u8 *mac_addr);
	s32 (*get_san_mac_addr)(struct txgbe_hw *hw, u8 *san_mac_addr);
	s32 (*set_san_mac_addr)(struct txgbe_hw *hw, u8 *san_mac_addr);
	s32 (*get_device_caps)(struct txgbe_hw *hw, u16 *device_caps);
	s32 (*get_wwn_prefix)(struct txgbe_hw *hw, u16 *wwnn_prefix,
				 u16 *wwpn_prefix);
	s32 (*setup_sfp)(struct txgbe_hw *hw);
	s32 (*enable_rx_dma)(struct txgbe_hw *hw, u32 regval);
	s32 (*disable_sec_rx_path)(struct txgbe_hw *hw);
	s32 (*enable_sec_rx_path)(struct txgbe_hw *hw);
	s32 (*disable_sec_tx_path)(struct txgbe_hw *hw);
	s32 (*enable_sec_tx_path)(struct txgbe_hw *hw);
	s32 (*acquire_swfw_sync)(struct txgbe_hw *hw, u32 mask);
	void (*release_swfw_sync)(struct txgbe_hw *hw, u32 mask);
	u64 (*autoc_read)(struct txgbe_hw *hw);
	void (*autoc_write)(struct txgbe_hw *hw, u64 value);
	s32 (*prot_autoc_read)(struct txgbe_hw *hw, bool *locked, u64 *value);
	s32 (*prot_autoc_write)(struct txgbe_hw *hw, bool locked, u64 value);
	s32 (*negotiate_api_version)(struct txgbe_hw *hw, int api);

	/* Link */
	void (*disable_tx_laser)(struct txgbe_hw *hw);
	void (*enable_tx_laser)(struct txgbe_hw *hw);
	void (*flap_tx_laser)(struct txgbe_hw *hw);
	s32 (*setup_link)(struct txgbe_hw *hw, u32 speed,
			       bool autoneg_wait_to_complete);
	s32 (*setup_mac_link)(struct txgbe_hw *hw, u32 speed,
			       bool autoneg_wait_to_complete);
	s32 (*check_link)(struct txgbe_hw *hw, u32 *speed,
			       bool *link_up, bool link_up_wait_to_complete);
	s32 (*get_link_capabilities)(struct txgbe_hw *hw,
				      u32 *speed, bool *autoneg);
	void (*set_rate_select_speed)(struct txgbe_hw *hw, u32 speed);

	/* Packet Buffer manipulation */
	void (*setup_pba)(struct txgbe_hw *hw, int num_pb, u32 headroom,
			     int strategy);

	/* LED */
	s32 (*led_on)(struct txgbe_hw *hw, u32 index);
	s32 (*led_off)(struct txgbe_hw *hw, u32 index);

	/* RAR, Multicast, VLAN */
	s32 (*set_rar)(struct txgbe_hw *hw, u32 index, u8 *addr, u32 vmdq,
			  u32 enable_addr);
	s32 (*set_uc_addr)(struct txgbe_hw *hw, u32 index, u8 *addr);
	s32 (*clear_rar)(struct txgbe_hw *hw, u32 index);
	s32 (*set_vmdq)(struct txgbe_hw *hw, u32 rar, u32 vmdq);
	s32 (*clear_vmdq)(struct txgbe_hw *hw, u32 rar, u32 vmdq);
	s32 (*init_rx_addrs)(struct txgbe_hw *hw);
	s32 (*update_mc_addr_list)(struct txgbe_hw *hw, u8 *mc_addr_list,
				      u32 mc_addr_count,
				      txgbe_mc_addr_itr func, bool clear);
	s32 (*clear_vfta)(struct txgbe_hw *hw);
	s32 (*set_vfta)(struct txgbe_hw *hw, u32 vlan,
			 u32 vind, bool vlan_on, bool vlvf_bypass);
	s32 (*set_vlvf)(struct txgbe_hw *hw, u32 vlan, u32 vind,
			   bool vlan_on, u32 *vfta_delta, u32 vfta,
			   bool vlvf_bypass);
	s32 (*init_uta_tables)(struct txgbe_hw *hw);
	void (*set_mac_anti_spoofing)(struct txgbe_hw *hw, bool enable, int vf);
	void (*set_vlan_anti_spoofing)(struct txgbe_hw *hw,
					bool enable, int vf);
	s32 (*update_xcast_mode)(struct txgbe_hw *hw, int xcast_mode);
	s32 (*set_rlpml)(struct txgbe_hw *hw, u16 max_size);

	/* Flow Control */
	s32 (*fc_enable)(struct txgbe_hw *hw);
	s32 (*setup_fc)(struct txgbe_hw *hw);
	void (*fc_autoneg)(struct txgbe_hw *hw);

	/* Manageability interface */
	s32 (*set_fw_drv_ver)(struct txgbe_hw *hw, u8 maj, u8 min, u8 build,
			 u8 ver, u16 len, char *driver_ver);
	s32 (*get_thermal_sensor_data)(struct txgbe_hw *hw);
	s32 (*init_thermal_sensor_thresh)(struct txgbe_hw *hw);
	void (*get_rtrup2tc)(struct txgbe_hw *hw, u8 *map);
	void (*disable_rx)(struct txgbe_hw *hw);
	void (*enable_rx)(struct txgbe_hw *hw);
	void (*set_ethertype_anti_spoofing)(struct txgbe_hw *hw,
						bool enable, int vf);
	s32 (*dmac_update_tcs)(struct txgbe_hw *hw);
	s32 (*dmac_config_tcs)(struct txgbe_hw *hw);
	s32 (*dmac_config)(struct txgbe_hw *hw);
	s32 (*setup_eee)(struct txgbe_hw *hw, bool enable_eee);

	enum txgbe_mac_type type;
	u8 perm_addr[ETH_ADDR_LEN];
	u8 san_addr[ETH_ADDR_LEN];
	/* prefix for World Wide Node Name (WWNN) */
	u16 wwnn_prefix;
	/* prefix for World Wide Port Name (WWPN) */
	u16 wwpn_prefix;

	u32 num_rar_entries;
	u32 max_tx_queues;
	u32 max_rx_queues;

	u8  san_mac_rar_index;
	u64 orig_autoc;  /* cached value of AUTOC */
	bool orig_link_settings_stored;
	bool autotry_restart;
	u8 flags;
	u32  max_link_up_time;
};

struct txgbe_phy_info {
	u32 (*get_media_type)(struct txgbe_hw *hw);
	s32 (*identify)(struct txgbe_hw *hw);
	s32 (*identify_sfp)(struct txgbe_hw *hw);
	s32 (*init)(struct txgbe_hw *hw);
	s32 (*reset)(struct txgbe_hw *hw);
	s32 (*read_reg)(struct txgbe_hw *hw, u32 reg_addr,
				u32 device_type, u16 *phy_data);
	s32 (*write_reg)(struct txgbe_hw *hw, u32 reg_addr,
				u32 device_type, u16 phy_data);
	s32 (*read_reg_mdi)(struct txgbe_hw *hw, u32 reg_addr,
				u32 device_type, u16 *phy_data);
	s32 (*write_reg_mdi)(struct txgbe_hw *hw, u32 reg_addr,
				u32 device_type, u16 phy_data);
	s32 (*setup_link)(struct txgbe_hw *hw);
	s32 (*setup_internal_link)(struct txgbe_hw *hw);
	s32 (*setup_link_speed)(struct txgbe_hw *hw, u32 speed,
				bool autoneg_wait_to_complete);
	s32 (*check_link)(struct txgbe_hw *hw, u32 *speed, bool *link_up);
	s32 (*read_i2c_byte)(struct txgbe_hw *hw, u8 byte_offset,
				u8 dev_addr, u8 *data);
	s32 (*write_i2c_byte)(struct txgbe_hw *hw, u8 byte_offset,
				u8 dev_addr, u8 data);
	s32 (*read_i2c_sff8472)(struct txgbe_hw *hw, u8 byte_offset,
				u8 *sff8472_data);
	s32 (*read_i2c_eeprom)(struct txgbe_hw *hw, u8 byte_offset,
				u8 *eeprom_data);
	s32 (*write_i2c_eeprom)(struct txgbe_hw *hw, u8 byte_offset,
				u8 eeprom_data);
	s32 (*check_overtemp)(struct txgbe_hw *hw);
	s32 (*set_phy_power)(struct txgbe_hw *hw, bool on);
	s32 (*handle_lasi)(struct txgbe_hw *hw);
	s32 (*read_i2c_byte_unlocked)(struct txgbe_hw *hw, u8 offset, u8 addr,
				      u8 *value);
	s32 (*write_i2c_byte_unlocked)(struct txgbe_hw *hw, u8 offset, u8 addr,
				       u8 value);

	enum txgbe_phy_type type;
	u32 addr;
	u32 id;
	enum txgbe_sfp_type sfp_type;
	bool sfp_setup_needed;
	u32 revision;
	u32 media_type;
	u32 phy_semaphore_mask;
	bool reset_disable;
	bool multispeed_fiber;
	bool qsfp_shared_i2c_bus;
	u32 nw_mng_if_sel;
};

struct txgbe_mbx_info {
	void (*init_params)(struct txgbe_hw *hw);
	s32  (*read)(struct txgbe_hw *hw, u32 *msg, u16 size, u16 vf_number);
	s32  (*write)(struct txgbe_hw *hw, u32 *msg, u16 size, u16 vf_number);
	s32  (*read_posted)(struct txgbe_hw *hw, u32 *msg, u16 size,
				u16 mbx_id);
	s32  (*write_posted)(struct txgbe_hw *hw, u32 *msg, u16 size,
				u16 mbx_id);
	s32  (*check_for_msg)(struct txgbe_hw *hw, u16 mbx_id);
	s32  (*check_for_ack)(struct txgbe_hw *hw, u16 mbx_id);
	s32  (*check_for_rst)(struct txgbe_hw *hw, u16 mbx_id);
};

enum txgbe_isb_idx {
	TXGBE_ISB_HEADER,
	TXGBE_ISB_MISC,
	TXGBE_ISB_VEC0,
	TXGBE_ISB_VEC1,
	TXGBE_ISB_MAX
};

struct txgbe_hw {
	void IOMEM *hw_addr;
	void *back;
	struct txgbe_mac_info mac;
	struct txgbe_phy_info phy;
	struct txgbe_link_info link;
	struct txgbe_rom_info rom;
	struct txgbe_flash_info flash;
	struct txgbe_bus_info bus;
	struct txgbe_mbx_info mbx;
	u16 device_id;
	u16 vendor_id;
	u16 subsystem_device_id;
	u16 subsystem_vendor_id;

	bool allow_unsupported_sfp;

	uint64_t isb_dma;
	void IOMEM *isb_mem;
	enum txgbe_reset_type {
		TXGBE_LAN_RESET = 0,
		TXGBE_SW_RESET,
		TXGBE_GLOBAL_RESET
	} reset_type;
};

#include "txgbe_regs.h"
#include "txgbe_dummy.h"

#endif /* _TXGBE_TYPE_H_ */
