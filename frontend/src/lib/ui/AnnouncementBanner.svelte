<script lang="ts">
    import { onMount } from 'svelte';
    import ArrowRight from 'phosphor-svelte/lib/ArrowRight';
    import X from 'phosphor-svelte/lib/X';
    import { announcement } from '$lib/announcement';

    // Keyed by the message text, so editing the wording shows the banner again
    // to people who dismissed the previous one.
    const dismissKey = announcement ? `cpmsoc-banner-dismissed:${announcement.message}` : '';

    let dismissed = $state(false);

    onMount(() => {
        if (!dismissKey) return;
        try {
            dismissed = localStorage.getItem(dismissKey) === '1';
        } catch {
            dismissed = false;
        }
    });

    function dismiss() {
        dismissed = true;
        if (!dismissKey) return;
        try {
            localStorage.setItem(dismissKey, '1');
        } catch {
            // storage unavailable (private mode) — banner just comes back next visit
        }
    }
</script>

{#if announcement && !dismissed}
    <div class="w-full bg-[#141414] text-white">
        <div
            class="mx-auto flex max-w-[1600px] items-center gap-3 px-3 py-2 font-mono text-[10px] leading-tight tracking-[0.05em] md:gap-4 md:px-6 md:text-xs md:tracking-[0.08em]"
        >
            <a
                href={announcement.href}
                class="group flex min-w-0 flex-1 items-center justify-between gap-3 hover:text-white/80 sm:justify-start"
            >
                <span class="min-w-0 uppercase leading-snug sm:truncate">{announcement.message}</span>

                <span class="inline-flex shrink-0 items-center gap-1 font-bold uppercase text-[#a893ff] group-hover:text-white">
                    {announcement.cta}
                    <ArrowRight size={12} weight="bold" />
                </span>
            </a>

            <button
                type="button"
                onclick={dismiss}
                aria-label="Dismiss announcement"
                class="shrink-0 p-1 text-white/50 transition-colors hover:text-white"
            >
                <X size={14} weight="bold" />
            </button>
        </div>
    </div>
{/if}
