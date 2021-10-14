vfs_read() {
  rw_verify_area() {
    security_file_permission() {
      selinux_file_permission() {
        __inode_security_revalidate() {
          _cond_resched();
        }
        avc_policy_seqno();
      }
      __fsnotify_parent();
      fsnotify();
    }
  }
  do_sync_read() {
    xfs_file_aio_read [xfs]() {
      xfs_file_buffered_aio_read [xfs]() {
        generic_segment_checks();
        xfs_ilock [xfs]() {
          down_read() {
            _cond_resched();
          }
        }
        generic_file_aio_read() {
          generic_segment_checks();
          _cond_resched();
          __find_get_page();
          page_cache_sync_readahead() {
            ondemand_readahead() {
              get_init_ra_size();
              __do_page_cache_readahead() {
                __page_cache_alloc() {
                  alloc_pages_current() {
                    get_task_policy.part.26();
                    policy_nodemask();
                    policy_zonelist();
                    __alloc_pages_nodemask() {
                      _cond_resched();
                      next_zones_zonelist();
                      get_page_from_freelist() {
                        next_zones_zonelist();
                        __zone_watermark_ok();
                        __mod_zone_page_state();
                        zone_statistics() {
                          __inc_zone_state();
                          __inc_zone_state();
                        }
                      }
                    }
                  }
                }
                blk_start_plug();
                xfs_vm_readpages [xfs]() {
                  mpage_readpages() {
                    add_to_page_cache_lru() {
                      __add_to_page_cache_locked() {
                        mem_cgroup_cache_charge() {
                          mem_cgroup_charge_common() {
                            __mem_cgroup_try_charge();
                            __mem_cgroup_commit_charge() {
                              lookup_page_cgroup();
                              mem_cgroup_charge_statistics.isra.21();
                              memcg_check_events();
                            }
                          }
                        }
                        kmem_cache_alloc() {
                          _cond_resched();
                        }
                        kmem_cache_alloc() {
                          _cond_resched();
                        }
                        kmem_cache_alloc() {
                          _cond_resched();
                        }
                        _raw_spin_lock_irq();
                        page_cache_tree_insert();
                        __inc_zone_page_state() {
                          __inc_zone_state();
                        }
                      }
                      lru_cache_add() {
                        __lru_cache_add();
                      }
                    }
                    do_mpage_readpage() {
                      xfs_get_blocks [xfs]() {
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
                      bdev_read_page();
                      bio_get_nr_vecs();
                      mpage_alloc() {
                        bio_alloc_bioset() {
                          mempool_alloc() {
                            _cond_resched();
                            mempool_alloc_slab() {
                              kmem_cache_alloc();
                            }
                          }
                          bio_init_aux();
                        }
                      }
                      //bio->bi_iter.bi_sector = blocks[0] << (blkbits - 9); set sector from block
                      bio_add_page() {
                        __bio_add_page() {
                          dm_merge_bvec [dm_mod]() {
                            dm_table_find_target [dm_mod]();
                            max_io_len [dm_mod]();
                            linear_merge [dm_mod]();
                          }
                        }
                      }
                    }
                    put_page();
                    mpage_bio_submit() {
                      guard_bio_eod();
                      submit_bio() {
                        generic_make_request() {
                          blk_queue_enter();
                          generic_make_request_checks() {
                            _cond_resched();
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
						   //list_add_tail(&req->queuelist, &plug->list); block requst by plug
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
                    }
                  }
                }
                put_pages_list();
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
                              }
                            }
                          }
                          scsi_init_cmd_errh();
                          scsi_dispatch_cmd() {
                            scsi_log_send();
                            ata_scsi_queuecmd [libata]() {
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
              }
            }
          }
          __find_get_page();
          _cond_resched();
          __lock_page_killable() {
            page_waitqueue();
            __wait_on_bit_lock() {
              prepare_to_wait_exclusive() {
                _raw_spin_lock_irqsave();
                _raw_spin_unlock_irqrestore();
              }
              bit_wait_io() {
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
                        } /* __schedule */
                      } /* schedule */
                    } /* schedule_timeout */
                    __delayacct_blkio_end() {
                      delayacct_end() {
                        ktime_get_ts64();
                        set_normalized_timespec();
                        _raw_spin_lock_irqsave();
                        _raw_spin_unlock_irqrestore();
                      }
                    }
                  } /* io_schedule_timeout */
                } /* io_schedule */
              } /* bit_wait_io */
              finish_wait();
            } /* __wait_on_bit_lock */
          } /* __lock_page_killable */
          unlock_page() {
            __smp_mb__after_atomic();
            page_waitqueue();
            __wake_up_bit();
          }
          mark_page_accessed();
          file_read_actor() {
            _cond_resched();
            __check_object_size() {
              static_key_enabled();
              __virt_addr_valid();
              check_stack_object();
            }
            //__copy_to_user()
          }
          put_page();
          _cond_resched();
          __find_get_page();
          put_page();
          touch_atime() {
            current_fs_time() {
              current_kernel_time();
            }
          }
        } /* generic_file_aio_read */
        xfs_iunlock [xfs]() {
          up_read();
        }
      } /* xfs_file_buffered_aio_read [xfs] */
    } /* xfs_file_aio_read [xfs] */
  } /* do_sync_read */
  __fsnotify_parent();
  fsnotify();
} /* vfs_read */
vfs_read() {
  rw_verify_area() {
    security_file_permission() {
      selinux_file_permission() {
        __inode_security_revalidate() {
          _cond_resched();
        }
        avc_policy_seqno();
      }
      __fsnotify_parent();
      fsnotify();
    }
  }
  do_sync_read() {
    xfs_file_aio_read [xfs]() {
      xfs_file_buffered_aio_read [xfs]() {
        generic_segment_checks();
        xfs_ilock [xfs]() {
          down_read() {
            _cond_resched();
          }
        }
        generic_file_aio_read() {
          generic_segment_checks();
          _cond_resched();
          __find_get_page();
          put_page();
          touch_atime() {
            current_fs_time() {
              current_kernel_time();
            }
          }
        }
        xfs_iunlock [xfs]() {
          up_read();
        }
      }
    }
  }
}
