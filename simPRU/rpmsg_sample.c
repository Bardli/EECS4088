#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rpmsg.h>

static void rpmsg_sample_cb(struct rpmsg_channel *rpdev, void *data, int len,
                                              void *priv, u32 src)
{
      print_hex_dump(KERN_INFO, "incoming message:", DUMP_PREFIX_NONE,
                                              16, 1, data, len, true);
}

static int rpmsg_sample_probe(struct rpmsg_channel *rpdev)
{
      int err;

      dev_info(&rpdev->dev, "chnl: 0x%x -> 0x%x\n", rpdev->src, rpdev->dst);

      /* send a message on our channel */
      err = rpmsg_send(rpdev->ept, "hello!", 6);
      if (err) {
              pr_err("rpmsg_send failed: %d\n", err);
              return err;
      }

      return 0;
}

static void rpmsg_sample_remove(struct rpmsg_channel *rpdev)
{
      dev_info(&rpdev->dev, "rpmsg sample client driver is removed\n");
}

static struct rpmsg_device_id rpmsg_driver_sample_id_table[] = {
      { .name = "rpmsg-client-sample" },
      { },
};
MODULE_DEVICE_TABLE(rpmsg, rpmsg_driver_sample_id_table);

static struct rpmsg_driver rpmsg_sample_client = {
      .drv.name       = KBUILD_MODNAME,
      .id_table       = rpmsg_driver_sample_id_table,
      .probe          = rpmsg_sample_probe,
      .callback       = rpmsg_sample_cb,
      .remove         = rpmsg_sample_remove,
};