#include <furi.h>
#include <furi_hal.h>
#include <m-string.h>
#include <cli/cli.h>
#include <storage/storage.h>
#include <loader/loader.h>
#include <toolbox/path.h>
#include <toolbox/tar/tar_archive.h>
#include <toolbox/args.h>

static void mtg_cli(Cli* cli, string_t args, void* context) {
    UNUSED(context);
    UNUSED(args);
    UNUSED(cli);
    string_t cmd;
    string_init(cmd);

    string_clear(cmd);
}

void mtg_on_system_start() {
#ifdef SRV_CLI
    Cli* cli = furi_record_open(RECORD_CLI);
    cli_add_command(cli, "mtg", CliCommandFlagDefault, mtg_cli, NULL);
    furi_record_close(RECORD_CLI);
// #else
//     UNUSED(mtg_cli);
#endif
}
