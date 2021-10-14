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
          mark_page_accessed();
          file_read_actor() {
            _cond_resched();
            __check_object_size() {
              static_key_enabled();
              __virt_addr_valid();
              check_stack_object();
            }
            // __copy_to_user
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
        }
        xfs_iunlock [xfs]() {
          up_read();
        }
      }
    }
  }
  __fsnotify_parent();
  fsnotify();
}
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
