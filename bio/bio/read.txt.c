 vfs_read() {
   rw_verify_area() {
     security_file_permission() {
       apparmor_file_permission() {
         common_file_perm() {
           aa_file_perm();
         }
       }
       __fsnotify_parent();
       fsnotify();
     }
   }
   __vfs_read() {
     new_sync_read() {
       ext4_file_read_iter() {
         generic_file_read_iter() {
           _cond_resched() {
             rcu_all_qs();
           }
           pagecache_get_page() {
             find_get_entry();
           }
           page_cache_sync_readahead() {
             ondemand_readahead() {
               __do_page_cache_readahead() {
                 __page_cache_alloc() {
                   alloc_pages_current() {
                     get_task_policy.part.30();
                     policy_nodemask();
                     policy_node();
                     __alloc_pages_nodemask() {
                       _cond_resched() {
                         rcu_all_qs();
                       }
                       __next_zones_zonelist();
                       get_page_from_freelist() {
                         __inc_numa_state();
                         __inc_numa_state();
                       }
                     }
                   }
                 }
                 blk_start_plug();
                 ext4_readpages() {
                   ext4_mpage_readpages() {
                     add_to_page_cache_lru() {
                       __add_to_page_cache_locked() {
                         PageHuge();
                         mem_cgroup_try_charge() {
                           get_mem_cgroup_from_mm();
                           try_charge();
                         }
                         _raw_spin_lock_irq();
                         page_cache_tree_insert() {
                           shmem_mapping();
                         }
                         __inc_node_page_state() {
                           __inc_node_state();
                         }
                         mem_cgroup_commit_charge() {
                           mem_cgroup_charge_statistics();
                           memcg_check_events();
                         }
                       }
                       lru_cache_add() {
                         __lru_cache_add();
                       }
                     }
                     ext4_map_blocks() {
                       ext4_es_lookup_extent() {
                         _raw_read_lock();
                       }
                       down_read() {
                         _cond_resched() {
                           rcu_all_qs();
                         }
                       }
                       ext4_ext_map_blocks() {
                         ext4_find_extent() {
                           __kmalloc() {
                             kmalloc_slab();
                             _cond_resched() {
                               rcu_all_qs();
                             }
                             memcg_kmem_put_cache();
                           }
                         }
                         ext4_ext_drop_refs();
                         kfree();
                       }
                       ext4_es_insert_extent() {
                         _raw_write_lock();
                         __es_remove_extent() {
                           __es_tree_search();
                         }
                         __es_insert_extent() {
                           kmem_cache_alloc() {
                             prefetch_freepointer();
                             memcg_kmem_put_cache();
                           }
                           _raw_spin_lock();
                         }
                       }
                       up_read();
                       __check_block_validity.constprop.78() {
                         ext4_data_block_valid();
                       }
                     }
                     bio_alloc_bioset() {
                       mempool_alloc() {
                         _cond_resched() {
                           rcu_all_qs();
                         }
                         mempool_alloc_slab() {
                           kmem_cache_alloc() {
                             prefetch_freepointer();
                             memcg_kmem_put_cache();
                           }
                         }
                       }
                       bio_init();
                     }
					 //bio->bi_iter.bi_sector = blocks[0] << (blkbits - 9); set sector from block
                     bio_add_page() {
                       __bio_try_merge_page();
                       __bio_add_page();
                     }
                     submit_bio() {
                       generic_make_request() {
                         generic_make_request_checks() {
                           _cond_resched() {
                             rcu_all_qs();
                           }
                           __disk_get_part();
                           kthread_blkcg();
                           bio_associate_blkcg();
                           blkg_lookup_slowpath();
                           blk_throtl_bio();
                         }
                         blk_queue_enter();
                         blk_queue_bio() {
                           blk_queue_bounce();
                           blk_queue_split();
                           bio_integrity_prep();
                           blk_attempt_plug_merge();
                           _raw_spin_lock_irq();
                           elv_merge() {
                             elv_rqhash_find();
                             cfq_merge() {
                               ioc_lookup_icq();
                               elv_rb_find();
                             }
                           }
                           wbt_wait();
                           get_request() {
                             blkg_lookup_slowpath();
                             elv_may_queue() {
                               cfq_may_queue() {
                                 ioc_lookup_icq();
                                 cfq_init_prio_data.isra.91();
                               }
                             }
                             ioc_lookup_icq();
                             mempool_alloc() {
                               _cond_resched() {
                                 rcu_all_qs();
                               }
                               alloc_request_size() {
                                 __kmalloc_node() {
                                   kmalloc_slab();
                                   memcg_kmem_put_cache();
                                 }
                                 scsi_old_init_rq() {
                                   kmem_cache_alloc_node() {
                                     prefetch_freepointer();
                                     memcg_kmem_put_cache();
                                   }
                                 }
                               }
                             }
                             blk_rq_init();
                             elv_set_request() {
                               cfq_set_request() {
                                 _raw_spin_lock_irq();
                               }
                             }
                             get_io_context();
                           }
                           blk_init_request_from_bio() {
                             blk_rq_bio_prep();
                           } 
						   //list_add_tail(&req->queuelist, &plug->list); block requst by plug
                           blk_account_io_start() {
                             disk_map_sector_rcu();
                             part_round_stats() {
                               part_in_flight();
                             }
                             part_inc_in_flight();
                           }
                         }
                       }
                     }
                   }
                 }
                 put_pages_list();
                 blk_finish_plug() {
                   blk_flush_plug_list() {
                     _raw_spin_lock();
                     __elv_add_request() {
                       elv_attempt_insert_merge() {
                         elv_rqhash_find();
                       }
                       elv_rqhash_add();
                       cfq_insert_request() {
                         cfq_init_prio_data.isra.91();
                         ktime_get();
                         cfq_add_rq_rb() {
                           elv_rb_add();
                           cfq_service_tree_add() {
                             ktime_get();
                             cfq_group_service_tree_add();
                           }
                           cfq_prio_tree_add();
                           cfq_prio_tree_add();
                         }
                         __cfq_update_io_thinktime() {
                           ktime_get();
                         }
                         __cfq_update_io_thinktime() {
                           ktime_get();
                         }
                         __cfq_update_io_thinktime() {
                           ktime_get();
                         }
                       }
                     }
                     queue_unplugged() {
                       __blk_run_queue() {
                         scsi_request_fn() {
                           blk_peek_request() {
                             cfq_dispatch_requests() {
                               ktime_get();
                               ktime_get();
                               ktime_get();
                               __cfq_set_active_queue() {
                                 ktime_get();
                                 hrtimer_try_to_cancel() {
                                   hrtimer_active();
                                 }
                               }
                               ktime_get();
                               cfq_should_idle();
                               cfq_dispatch_insert() {
                                 cfq_find_next_rq();
                                 cfq_remove_request() {
                                   elv_rb_del();
                                 }
                                 elv_dispatch_sort() {
                                   elv_rqhash_del.part.11();
                                 }
                               }
                             }
                             cfq_activate_request();
                             scsi_prep_fn() {
                               scsi_prep_state_check();
                               get_device();
                               scsi_init_command() {
                                 scsi_req_init();
                                 init_timer_key();
                                 scsi_add_cmd_to_list();
                               }
                               scsi_setup_cmnd() {
                                 sd_init_command() {
                                   sd_setup_read_write_cmnd() {
                                     scsi_init_io() {
                                       scsi_init_sgtable() {
                                         mempool_alloc() {
                                           mempool_alloc_slab() {
                                             kmem_cache_alloc() {
                                               prefetch_freepointer();
                                               memcg_kmem_put_cache();
                                             }
                                           }
                                         }
                                         blk_rq_map_sg();
                                       }
                                     }
                                   }
                                 }
                               }
                             }
                           }
                           blk_queue_start_tag() {
                             blk_start_request() {
                               ktime_get();
                               wbt_issue();
                               blk_add_timer() {
                                 round_jiffies_up();
                                 round_jiffies_up();
                                 mod_timer() {
                                   lock_timer_base() {
                                     _raw_spin_lock_irqsave();
                                   }
                                   detach_if_pending();
                                   get_nohz_timer_target();
                                   _raw_spin_lock();
                                   __internal_add_timer() {
                                     calc_wheel_index();
                                   }
                                   trigger_dyntick_cpu.isra.35();
                                   _raw_spin_unlock_irqrestore();
                                 }
                               }
                             }
                           }
                           scsi_init_cmd_errh();
                           scsi_dispatch_cmd() {
                             scsi_log_send();
                             ata_scsi_queuecmd() {
                               _raw_spin_lock_irqsave();
                               ata_scsi_find_dev() {
                                 __ata_scsi_find_dev() {
                                   ata_find_dev();
                                 }
                               }
                               ata_scsi_translate() {
                                 ata_qc_new_init();
                                 ata_sg_init();
                                 ata_scsi_rw_xlat() {
                                   ata_build_rw_tf();
                                 }
                                 ahci_pmp_qc_defer [libahci]() {
                                   ata_std_qc_defer();
                                 }
                                 ata_qc_issue() {
                                   map_sg() {
                                     get_domain() {
                                       check_device.part.17();
                                     }
                                     sg_num_pages();
                                     dma_ops_alloc_iova.isra.25() {
                                       alloc_iova_fast() {
                                         _raw_spin_lock_irqsave();
                                         _raw_spin_unlock_irqrestore();
                                       }
                                     }
                                     iommu_map_page();
                                   }
                                   ahci_qc_prep [libahci]() {
                                     ata_tf_to_fis();
                                   }
                                   ahci_qc_issue [libahci]();
                                 }
                               }
                               _raw_spin_unlock_irqrestore();
                             }
                           }
                           _raw_spin_lock_irq();
                           blk_peek_request() {
                             cfq_dispatch_requests() {
                               ktime_get();
                             }
                           }
                         }
                       }
                     }
                   }
                 }
               }
             }
           }
           pagecache_get_page() {
             find_get_entry();
           }
           _raw_spin_lock_irq();
           io_schedule() {
             io_schedule_prepare();
             schedule() {
               rcu_note_context_switch();
               _raw_spin_lock();
               update_rq_clock();
               deactivate_task() {
                 dequeue_task_fair() {
                   dequeue_entity() {
                     update_curr() {
                       update_min_vruntime();
                       cpuacct_charge();
                       __cgroup_account_cputime() {
                         cgroup_cpu_stat_updated();
                       }
                     }
                     __update_load_avg_se.isra.38();
                     clear_buddies();
                     account_entity_dequeue();
                     update_cfs_group();
                   }
                   dequeue_entity() {
                     update_curr() {
                       __calc_delta();
                       update_min_vruntime();
                     }
                     __update_load_avg_se.isra.38();
                     clear_buddies();
                     account_entity_dequeue();
                     update_cfs_group() {
                       reweight_entity();
                     }
                   }
                   hrtick_update();
                 }
               }
               __delayacct_blkio_start() {
                 ktime_get();
               }
               pick_next_task_fair() {
                 __msecs_to_jiffies();
               }
               pick_next_task_idle() {
                 put_prev_task_fair() {
                   put_prev_entity() {
                     check_cfs_rq_runtime();
                   }
                   put_prev_entity() {
                     check_cfs_rq_runtime();
                   }
                 }
                 __update_idle_core();
               }
               finish_task_switch() {
                 __mmdrop() {
                   pgd_free() {
                     _raw_spin_lock();
                     free_pages() {
                       free_pages.part.90() {
                         __free_pages() {
                           __free_pages_ok() {
                             memcg_kmem_uncharge() {
                               page_counter_uncharge() {
                                 page_counter_cancel();
                                 page_counter_cancel();
                               }
                               page_counter_uncharge() {
                                 page_counter_cancel();
                                 page_counter_cancel();
                               }
                             }
                             free_one_page() {
                               _raw_spin_lock();
                               __mod_zone_page_state();
                             }
                           }
                         }
                       }
                     }
                   }
                   destroy_context_ldt();
                   hmm_mm_destroy() {
                     kfree();
                   }
                   kmem_cache_free() {
                     __slab_free();
                   }
                 }
               }
             } /* schedule */
           } /* io_schedule */
           finish_wait();
           mark_page_accessed();
           _cond_resched() {
             rcu_all_qs();
           }
           _cond_resched() {
             rcu_all_qs();
           }
           pagecache_get_page() {
             find_get_entry();
           }
           touch_atime() {
             __atime_needs_update() {
               current_time() {
                 current_kernel_time64();
                 timespec_trunc();
               }
             }
           }
         } /* generic_file_read_iter */
       } /* ext4_file_read_iter */
     } /* new_sync_read */
   } /* __vfs_read */
   __fsnotify_parent();
   fsnotify();
 } /* vfs_read */
 vfs_read() {
   rw_verify_area() {
     security_file_permission() {
       apparmor_file_permission() {
         common_file_perm() {
           aa_file_perm();
         }
       }
       __fsnotify_parent();
       fsnotify();
     }
   }
   __vfs_read() {
     new_sync_read() {
       ext4_file_read_iter() {
         generic_file_read_iter() {
           _cond_resched() {
             rcu_all_qs();
           }
           pagecache_get_page() {
             find_get_entry();
           }
           touch_atime() {
             __atime_needs_update() {
               current_time() {
                 current_kernel_time64();
                 timespec_trunc();
               }
             }
           }
         }
       }
     }
   }
 }
