vfs_write() {
  rw_verify_area() {
    security_file_permission() {
      selinux_file_permission() {
        __inode_security_revalidate() {
          _cond_resched();
        }
        avc_policy_seqno();
      }
    }
  }
  __sb_start_write();
  do_sync_write() {
    xfs_file_aio_write [xfs]() {
      generic_segment_checks();
      xfs_file_dio_aio_write [xfs]() {
        xfs_ilock [xfs]() {
          down_read() {
            _cond_resched();
          }
        }
        xfs_file_aio_write_checks [xfs]() {
          xfs_break_layouts [xfs]() {
            xfs_break_leased_layouts [xfs]();
          }
          _raw_spin_lock_irqsave();
          _raw_spin_unlock_irqrestore();
          file_update_time() {
            current_fs_time() {
              current_kernel_time();
            }
            __mnt_want_write_file() {
              mnt_clone_write();
            }
            update_time() {
              xfs_vn_update_time [xfs]() {
                xfs_trans_alloc [xfs]() {
                  __sb_start_write();
                  kmem_zone_alloc [xfs]() {
                    kmem_cache_alloc() {
                      _cond_resched();
                    }
                  }
                  xfs_trans_reserve [xfs]() {
                    xfs_log_reserve [xfs]() {
                      xlog_ticket_alloc [xfs]() {
                        kmem_zone_alloc [xfs]() {
                          kmem_cache_alloc() {
                            _cond_resched();
                          }
                        }
                        xfs_log_calc_unit_res [xfs]();
                      }
                      xlog_grant_push_ail [xfs]() {
                        xlog_space_left [xfs]();
                      }
                      xlog_grant_head_check [xfs]() {
                        xlog_space_left [xfs]();
                      }
                      xlog_grant_add_space.isra.6 [xfs]();
                      xlog_grant_add_space.isra.6 [xfs]();
                    }
                  }
                }
                xfs_ilock [xfs]() {
                  down_write() {
                    _cond_resched();
                  }
                }
                xfs_trans_ijoin [xfs]() {
                  xfs_trans_add_item [xfs]() {
                    kmem_zone_alloc [xfs]() {
                      kmem_cache_alloc() {
                        _cond_resched();
                      }
                    }
                  }
                }
                xfs_trans_log_inode [xfs]();
                xfs_trans_commit [xfs]() {
                  __xfs_trans_commit [xfs]() {
                    xfs_trans_apply_dquot_deltas [xfs]();
                    xfs_log_commit_cil [xfs]() {
                      xfs_inode_item_size [xfs]() {
                        xfs_inode_item_data_fork_size.isra.2 [xfs]();
                        xfs_inode_item_attr_fork_size.isra.3 [xfs]();
                      }
                      down_read() {
                        _cond_resched();
                      }
                      xfs_inode_item_format [xfs]() {
                        xfs_inode_item_format_data_fork.isra.6 [xfs]() {
                          xfs_iextents_copy [xfs]() {
                            xfs_iext_get_ext [xfs]();
                            xfs_bmbt_get_startblock [xfs]();
                          }
                        }
                        xfs_inode_item_format_attr_fork.isra.7 [xfs]();
                      }
                      xfs_cil_prepare_item.isra.2 [xfs]();
                      _raw_spin_lock();
                      xfs_log_done [xfs]() {
                        xlog_ungrant_log_space [xfs]() {
                          xlog_grant_sub_space.isra.5 [xfs]();
                          xlog_grant_sub_space.isra.5 [xfs]();
                          xfs_log_space_wake [xfs]();
                        }
                        xfs_log_ticket_put [xfs]() {
                          kmem_cache_free();
                        }
                      }
                      xfs_trans_unreserve_and_mod_sb [xfs]();
                      xfs_trans_free_items [xfs]() {
                        xfs_inode_item_committing [xfs]();
                        xfs_inode_item_unlock [xfs]() {
                          xfs_iunlock [xfs]() {
                            up_write();
                          }
                        }
                        xfs_trans_free_item_desc [xfs]() {
                          kmem_cache_free();
                        }
                      }
                      up_read();
                    }
                    xfs_trans_free [xfs]() {
                      xfs_extent_busy_clear [xfs]();
                      __sb_end_write();
                      xfs_trans_free_dqinfo [xfs]();
                      kmem_cache_free();
                    }
                  }
                }
              }
            }
            __mnt_drop_write_file();
          }
        }
        filemap_write_and_wait_range() {
          __filemap_fdatawrite_range() {
            do_writepages() {
              xfs_vm_writepages [xfs]() {
                _raw_spin_lock();
                write_cache_pages() {
                  tag_pages_for_writeback() {
                    _raw_spin_lock_irq();
                    _cond_resched();
                  }
                  pagevec_lookup_tag() {
                    find_get_pages_tag();
                  }
                }
              }
            }
          }
          filemap_fdatawait_range() {
            __filemap_fdatawait_range() {
              pagevec_lookup_tag() {
                find_get_pages_tag();
              }
            }
            filemap_check_errors();
          }
        }
        invalidate_inode_pages2_range() {
          __pagevec_lookup() {
            __find_get_pages();
          }
          mem_cgroup_uncharge_start();
          _cond_resched();
          try_to_release_page() {
            xfs_vm_releasepage [xfs]() {
              xfs_count_page_state [xfs]();
              try_to_free_buffers() {
                _raw_spin_lock();
                drop_buffers() {
                  put_page();
                }
                cancel_dirty_page();
                free_buffer_head() {
                  kmem_cache_free() {
                    __slab_free();
                  }
                }
              }
            }
          }
          _raw_spin_lock_irq();
          __delete_from_page_cache() {
            __dec_zone_page_state() {
              __dec_zone_state();
            }
          }
          mem_cgroup_uncharge_cache_page() {
            __mem_cgroup_uncharge_common() {
              lookup_page_cgroup();
              mem_cgroup_charge_statistics.isra.21();
              memcg_check_events();
            }
          }
          put_page();
          unlock_page() {
            __smp_mb__after_atomic();
            page_waitqueue();
            __wake_up_bit();
          }
          pagevec_remove_exceptionals();
          __pagevec_release() {
            lru_add_drain_cpu() {
              pagevec_lru_move_fn() {
                _raw_spin_lock_irqsave();
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                mem_cgroup_page_lruvec() {
                  lookup_page_cgroup();
                }
                __pagevec_lru_add_fn() {
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                }
                _raw_spin_unlock_irqrestore();
                release_pages() {
                  _raw_spin_lock_irqsave();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  mem_cgroup_page_lruvec() {
                    lookup_page_cgroup();
                  }
                  mem_cgroup_update_lru_size();
                  __mod_zone_page_state();
                  _raw_spin_unlock_irqrestore();
                  free_hot_cold_page_list() {
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                    free_hot_cold_page() {
                      free_pages_prepare();
                      get_pageblock_flags_group();
                    }
                  }
                }
              }
            }
            release_pages() {
              _raw_spin_lock_irqsave();
              mem_cgroup_page_lruvec() {
                lookup_page_cgroup();
              }
              mem_cgroup_update_lru_size();
              __mod_zone_page_state();
              _raw_spin_unlock_irqrestore();
              free_hot_cold_page_list() {
                free_hot_cold_page() {
                  free_pages_prepare();
                  get_pageblock_flags_group();
                }
              }
            }
          }
          mem_cgroup_uncharge_end();
          _cond_resched();
        }
        __blockdev_direct_IO() {
          kmem_cache_alloc() {
            _cond_resched();
          }
          blk_start_plug();
          get_user_pages_fast() {
            gup_pud_range() {
              gup_pte_range();
            }
          }
          xfs_get_blocks_direct [xfs]() {
            __xfs_get_blocks [xfs]() {
              xfs_ilock_data_map_shared [xfs]() {
                xfs_ilock [xfs]() {
                  down_read() {
                    _cond_resched();
                  }
                }
              }
              xfs_bmapi_read [xfs]() {
                xfs_iext_lookup_extent [xfs]() {
                  xfs_iext_bno_to_ext [xfs]() {
                    xfs_bmbt_get_startoff [xfs]();
                    xfs_bmbt_get_blockcount [xfs]();
                  }
                  xfs_bmbt_get_all [xfs]() {
                    __xfs_bmbt_get_all [xfs]();
                  }
                }
                xfs_bmapi_trim_map.isra.15 [xfs]();
                xfs_bmapi_update_map [xfs]();
              }
              xfs_iunlock [xfs]() {
                up_read();
              }
              xfs_map_buffer.isra.10 [xfs]() {
                xfs_fsb_to_db [xfs]();
              }
            }
          }
          dio_set_defer_completion.isra.9();
          put_page();
          bio_get_nr_vecs();
          bio_alloc_bioset() {
            mempool_alloc() {
              _cond_resched();
              mempool_alloc_slab() {
                kmem_cache_alloc();
              }
            }
            bio_init_aux();
          }
          bio_add_page() {
            __bio_add_page() {
              dm_merge_bvec [dm_mod]() {
                dm_table_find_target [dm_mod]();
                max_io_len [dm_mod]();
                linear_merge [dm_mod]();
              }
            }
          }
          put_page();
          _raw_spin_lock_irqsave();
          _raw_spin_unlock_irqrestore();
          submit_bio() {
            generic_make_request() {
              blk_queue_enter();
              generic_make_request_checks() {
                _cond_resched();
                create_task_io_context() {
                  kmem_cache_alloc_node();
                  _raw_spin_lock();
                }
                blk_throtl_bio() {
                  throtl_update_dispatch_stats();
                }
              }
              dm_make_request [dm_mod]() {
                __srcu_read_lock();
                __split_and_process_bio [dm_mod]() {
                  mempool_alloc() {
                    _cond_resched();
                    mempool_alloc_slab() {
                      kmem_cache_alloc();
                    }
                  }
                  part_round_stats() {
                    part_in_flight();
                    part_round_stats_single.isra.44();
                  }
                  dm_table_find_target [dm_mod]();
                  max_io_len [dm_mod]();
                  __clone_and_map_data_bio [dm_mod]() {
                    bio_alloc_bioset() {
                      mempool_alloc() {
                        _cond_resched();
                        mempool_alloc_slab() {
                          kmem_cache_alloc();
                        }
                      }
                      bio_init_aux();
                    }
                    __bio_clone();
                    __map_bio [dm_mod]() {
                      blk_start_plug();
                      linear_map [dm_mod]();
                      blk_finish_plug() {
                        blk_flush_plug_list();
                      }
                      generic_make_request() {
                        blk_queue_enter();
                        generic_make_request_checks() {
                          _cond_resched();
                          blk_throtl_bio() {
                            throtl_update_dispatch_stats();
                          }
                        }
                      }
                    }
                  }
                  dec_pending [dm_mod]();
                }
                __srcu_read_unlock();
              }
              blk_queue_enter();
              blk_queue_bio() {
                blk_queue_bounce();
                bio_integrity_enabled();
                blk_attempt_plug_merge();
                _raw_spin_lock_irq();
                elv_merge() {
                  elv_rqhash_find();
                  deadline_merge() {
                    elv_rb_find();
                  }
                }
                get_request() {
                  elv_may_queue();
                  mempool_alloc() {
                    _cond_resched();
                    alloc_request_simple() {
                      kmem_cache_alloc_node();
                    }
                  }
                  blk_rq_init();
                  elv_set_request();
                }
                init_request_from_bio() {
                  blk_rq_bio_prep() {
                    blk_recount_segments() {
                      __blk_recalc_rq_segments();
                    }
                  }
                }
                blk_account_io_start() {
                  disk_map_sector_rcu();
                  part_round_stats() {
                    part_in_flight();
                    part_round_stats_single.isra.44();
                    part_round_stats_single.isra.44();
                  }
                  part_inc_in_flight();
                }
              }
            }
          }
          blk_finish_plug() {
            blk_flush_plug_list() {
              plug_rq_cmp();
              _raw_spin_lock();
              __elv_add_request() {
                elv_attempt_insert_merge() {
                  elv_rqhash_find();
                }
                elv_rqhash_add();
                deadline_add_request() {
                  elv_rb_add();
                }
              }
              queue_unplugged() {
                __blk_run_queue() {
                  scsi_request_fn() {
                    blk_peek_request() {
                      deadline_dispatch_requests() {
                        deadline_remove_request.isra.6() {
                          elv_rb_del();
                        }
                        elv_dispatch_add_tail() {
                          elv_rqhash_del.part.6();
                        }
                      }
                      scsi_prep_fn() {
                        scsi_prep_state_check();
                        get_device();
                        scsi_get_command() {
                          __scsi_get_command() {
                            scsi_host_alloc_command() {
                              kmem_cache_alloc();
                              kmem_cache_alloc();
                            }
                          }
                          init_timer_key();
                          _raw_spin_lock_irqsave();
                          _raw_spin_unlock_irqrestore();
                        }
                        scsi_setup_cmnd() {
                          sd_init_command [sd_mod]() {
                            sd_setup_read_write_cmnd [sd_mod]() {
                              scsi_init_io() {
                                scsi_init_sgtable() {
                                  mempool_alloc() {
                                    mempool_alloc_slab() {
                                      kmem_cache_alloc();
                                    }
                                  }
                                  blk_rq_map_sg() {
                                    __blk_segment_map_sg();
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    blk_queue_start_tag() {
                      blk_start_request() {
                        blk_dequeue_request();
                        blk_add_timer() {
                          round_jiffies_up();
                          round_jiffies_up();
                          mod_timer() {
                            lock_timer_base.isra.37() {
                              _raw_spin_lock_irqsave();
                            }
                            detach_if_pending();
                            get_nohz_timer_target();
                            _raw_spin_lock();
                            internal_add_timer() {
                              __internal_add_timer();
                              wake_up_nohz_cpu();
                            }
                            _raw_spin_unlock_irqrestore();
                          }
                        }
                      }
                    }
                    scsi_init_cmd_errh();
                    scsi_dispatch_cmd() {
                      scsi_log_send();
                      ata_scsi_queuecmd [libata]() { //queuecmd
                        _raw_spin_lock_irqsave();
                        ata_scsi_find_dev [libata]() {
                          __ata_scsi_find_dev [libata]() {
                            ata_find_dev.part.17 [libata]();
                          }
                        }
                        ata_qc_new_init [libata]();
                        ata_sg_init [libata]();
                        ata_scsi_rw_xlat [libata]() {
                          ata_build_rw_tf [libata]();
                        }
                        ahci_pmp_qc_defer [libahci]() {
                          ata_std_qc_defer [libata]();
                        }
                        ata_qc_issue [libata]() {
                          map_sg() {
                            get_domain() {
                              check_device();
                            }
                            sg_num_pages();
                            dma_ops_alloc_iova.isra.23() {
                              alloc_iova_fast() {
                                iova_rcache_get() {
                                  _raw_spin_lock_irqsave();
                                  _raw_spin_unlock_irqrestore();
                                }
                              }
                            }
                            iommu_map_page();
                          }
                          ahci_qc_prep [libahci]() {
                            ata_tf_to_fis [libata]();
                          }
                          ahci_qc_issue [libahci]();
                        }
                        _raw_spin_unlock_irqrestore();
                      }
                    }
                    _raw_spin_lock_irq();
                    blk_peek_request() {
                      deadline_dispatch_requests();
                    }
                  }
                }
              }
            }
          }
          _raw_spin_lock_irqsave();
          _raw_spin_unlock_irqrestore();
          io_schedule() {
            io_schedule_timeout() {
              __delayacct_blkio_start() {
                ktime_get_ts64();
              }
              schedule_timeout() {
                schedule() {
                  __schedule() {
                    rcu_note_context_switch();
                    _raw_spin_lock_irq();
                    deactivate_task() {
                      update_rq_clock.part.78();
                      dequeue_task_fair() {
                        dequeue_entity() {
                          update_curr() {
                            update_min_vruntime();
                            cpuacct_charge();
                          }
                          update_cfs_rq_blocked_load();
                          clear_buddies();
                          account_entity_dequeue();
                          update_min_vruntime();
                          update_cfs_shares();
                        }
                        hrtick_update();
                      }
                    }
                    idle_balance() {
                      msecs_to_jiffies();
                    }
                    put_prev_task_fair();
                    pick_next_task_fair();
                    pick_next_task_idle();
                    finish_task_switch();
                  }
                }
              }
              __delayacct_blkio_end() {
                delayacct_end() {
                  ktime_get_ts64();
                  set_normalized_timespec();
                  _raw_spin_lock_irqsave();
                  _raw_spin_unlock_irqrestore();
                }
              }
            }
          }
          _raw_spin_lock_irqsave();
          _raw_spin_unlock_irqrestore();
          dio_bio_complete() {
            put_page();
            bio_put() {
              bio_disassociate_task();
              mempool_free() {
                mempool_free_slab() {
                  kmem_cache_free();
                }
              }
            }
          }
          _raw_spin_lock_irqsave();
          _raw_spin_unlock_irqrestore();
          _raw_spin_lock_irqsave();
          _raw_spin_unlock_irqrestore();
          dio_complete() {
            xfs_end_io_direct_write [xfs]() {
              _raw_spin_lock_irqsave();
              _raw_spin_unlock_irqrestore();
              xfs_setfilesize [xfs]() {
                xfs_trans_alloc [xfs]() {
                  __sb_start_write();
                  kmem_zone_alloc [xfs]() {
                    kmem_cache_alloc() {
                      _cond_resched();
                    }
                  }
                  xfs_trans_reserve [xfs]() {
                    xfs_log_reserve [xfs]() {
                      xlog_ticket_alloc [xfs]() {
                        kmem_zone_alloc [xfs]() {
                          kmem_cache_alloc() {
                            _cond_resched();
                          }
                        }
                        xfs_log_calc_unit_res [xfs]();
                      }
                      xlog_grant_push_ail [xfs]() {
                        xlog_space_left [xfs]();
                      }
                      xlog_grant_head_check [xfs]() {
                        xlog_space_left [xfs]();
                      }
                      xlog_grant_add_space.isra.6 [xfs]();
                      xlog_grant_add_space.isra.6 [xfs]();
                    }
                  }
                }
                __xfs_setfilesize [xfs]() {
                  xfs_ilock [xfs]() {
                    down_write() {
                      _cond_resched();
                    }
                  }
                  xfs_trans_ijoin [xfs]() {
                    xfs_trans_add_item [xfs]() {
                      kmem_zone_alloc [xfs]() {
                        kmem_cache_alloc() {
                          _cond_resched();
                        }
                      }
                    }
                  }
                  xfs_trans_log_inode [xfs]();
                  xfs_trans_commit [xfs]() {
                    __xfs_trans_commit [xfs]() {
                      xfs_trans_apply_dquot_deltas [xfs]();
                      xfs_log_commit_cil [xfs]() {
                        xfs_inode_item_size [xfs]() {
                          xfs_inode_item_data_fork_size.isra.2 [xfs]();
                          xfs_inode_item_attr_fork_size.isra.3 [xfs]();
                        }
                        down_read() {
                          _cond_resched();
                        }
                        xfs_inode_item_format [xfs]() {
                          xfs_inode_item_format_data_fork.isra.6 [xfs]() {
                            xfs_iextents_copy [xfs]() {
                              xfs_iext_get_ext [xfs]();
                              xfs_bmbt_get_startblock [xfs]();
                            }
                          }
                          xfs_inode_item_format_attr_fork.isra.7 [xfs]();
                        }
                        xfs_cil_prepare_item.isra.2 [xfs]();
                        _raw_spin_lock();
                        xfs_log_done [xfs]() {
                          xlog_ungrant_log_space [xfs]() {
                            xlog_grant_sub_space.isra.5 [xfs]();
                            xlog_grant_sub_space.isra.5 [xfs]();
                            xfs_log_space_wake [xfs]();
                          }
                          xfs_log_ticket_put [xfs]() {
                            kmem_cache_free();
                          }
                        }
                        xfs_trans_unreserve_and_mod_sb [xfs]();
                        xfs_trans_free_items [xfs]() {
                          xfs_inode_item_committing [xfs]();
                          xfs_inode_item_unlock [xfs]() {
                            xfs_iunlock [xfs]() {
                              up_write();
                            }
                          }
                          xfs_trans_free_item_desc [xfs]() {
                            kmem_cache_free();
                          }
                        }
                        up_read();
                      }
                      xfs_trans_free [xfs]() {
                        xfs_extent_busy_clear [xfs]();
                        __sb_end_write();
                        xfs_trans_free_dqinfo [xfs]();
                        kmem_cache_free();
                      }
                    }
                  }
                }
              }
            }
            wake_up_bit() {
              bit_waitqueue();
              __wake_up_bit();
            }
            kmem_cache_free();
          }
        }
        xfs_iunlock [xfs]() {
          up_read();
        }
      }
      generic_write_sync();
    }
  }
  __fsnotify_parent();
  fsnotify();
  __sb_end_write();
}
